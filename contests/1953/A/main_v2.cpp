#include <bits/stdc++.h>
using namespace std;

constexpr size_t block_size = 16;

typedef pair<int,double> IndexFloat;

////////////////////////
// simulated binary16 //
////////////////////////

class Float16{
    
    public:    
        Float16(double in) : value(in)
        {
            truncate();
        }

        Float16() : value(0) {}

        Float16& operator=(double rhs)
        {
            value = rhs;
            truncate();
            return *this;
        }

        friend Float16 operator+(Float16 lhs, Float16 rhs)
        {
            double tmp = lhs.value + rhs.value;
            return Float16(tmp);
        }

        operator float() const
        {
            return static_cast<float>(value);
        }

        operator double() const
        {
            return value;
        }

    private:

        static const uint32_t mantissa_shift = 42;
        static const uint32_t exp_shift_mid   = 56;
        static const uint32_t exp_shift_out   = 52;
        static const uint64_t exp_exp_mid = (63llu << exp_shift_mid);
        static const uint64_t mask_exp_out = (15llu << exp_shift_out);
        static const uint64_t mask_exp_lead = (1llu << 62);
        static const uint64_t mask_mantissa_d = (1llu << 63) + mask_exp_lead + exp_exp_mid + mask_exp_out;

        void truncate()
        {
            uint64_t utmp;
            memcpy(&utmp, &value, sizeof utmp);
            //zeroing mantissa bits starting from 11th (this is NOT rounding)
            utmp = utmp >> mantissa_shift;
            utmp = utmp << mantissa_shift;
            //setting masks for 5-bit exponent extraction out of 11-bit one
            
            if (utmp & mask_exp_lead) {// checking leading bit, suspect overflow
                if (utmp & exp_exp_mid) { //Detected overflow if at least 1 bit is non-zero
                    //Assign Inf with proper sign
                    utmp = utmp | exp_exp_mid; //setting 1s in the middle 6 bits of of exponent
                    utmp = utmp & mask_mantissa_d; //zeroing mantissa irrelative of original values to prevent NaN
                    utmp = utmp | mask_exp_out; //setting 1s in the last 4 bits of exponent
                }
            } else { //checking small numbers according to exponent range
                if ((utmp & exp_exp_mid) != exp_exp_mid) { //Detected underflow if at least 1 bit is 0
                    utmp = 0;
                }
            }
            memcpy(&value, &utmp, sizeof utmp);
        }
        
        double value;

};


////////////////
// expression //
////////////////




class Expression
{
    private:
        struct Sum;
    
    public:

        typedef shared_ptr<Expression> Ptr;

        static Ptr create(int i, double float_value)
        {
            return make_shared<Expression>(IndexFloat(i, float_value));
        }

        template<class... Summands>
        static Ptr sum(char type, Summands&&... summands)
        {
            return make_shared<Expression>(type, vector<Ptr>{forward<Summands>(summands)...});
        }

        Expression(const IndexFloat& value) : value(value), ans_is_cached(true), cached_ans(value.second)
        {
        }

        Expression(char type, vector<Ptr> summands) : value(Sum{move(summands), type}), ans_is_cached(false)
        {
        }

        double eval() const
        {
            if (dirty())
            {
                cached_ans = do_eval();
                ans_is_cached = true;
            }
            return cached_ans;
        }

        bool is_atomic() const
        {
            return value.index() == 0;
        }

        const IndexFloat& get_atomic_value() const
        {
            return get<IndexFloat>(value);
        }

        void add_summand(Ptr summand, char default_type = 'd')
        {
            if (is_atomic())
            {
                auto[index,float_value] = get_atomic_value();
                value = Sum{{Expression::create(index,float_value)}, default_type};
            }
            get<Sum>(value).summands.push_back(summand);
        }

        const vector<Ptr>& get_summands() const
        {
            return get<Sum>(value).summands;
        }

        char get_sum_type() const
        {
            return get<Sum>(value).type;
        }

        void set_sum_type(char type)
        {
            get<Sum>(value).type = type;
            ans_is_cached = false;
        }

        void print(ostream& out, bool use_indices = true, bool print_nl = true)
        {
            if (is_atomic())
            {
                auto[index,float_value] = get_atomic_value();
                if (use_indices)
                {
                    out << index;
                }
                else
                {
                    out << float_value;
                }
            }
            else
            {
                const auto& sum = get<Sum>(value);
                out << '{' << sum.type << ':';
                for (size_t i = 0; i < sum.summands.size(); ++i)
                {
                    if (i > 0)
                    {
                        out << ',';
                    }
                    sum.summands[i]->print(out, use_indices, false);
                }
                out << '}';
            }
            if (print_nl)
            {
                out << '\n';
            }
        }

        vector<IndexFloat> in_order() const
        {

            vector<IndexFloat> result;
            stack<const Expression*> stk;
            stk.push(this);
            while (!stk.empty())
            {
                auto* e = stk.top();
                stk.pop();
                if (e->is_atomic())
                {
                    result.push_back(e->get_atomic_value());
                }
                else
                {
                    const auto& summands = e->get_summands();
                    for (int i = summands.size()-1; i >= 0; --i)
                    {
                        stk.push(summands[i].get());
                    }
                }
            }
            return result;
        }

        double random_penalty() const
        {
            size_t violations = 0;
            auto elements = in_order();
            for (size_t i = 0; i < elements.size(); i+=block_size)
            {
                int pos_i = elements[i].first;
                for (size_t j = i+1; j < min(elements.size(), i + block_size); ++j)
                {
                    int pos_j = elements[j].first;
                    violations += abs(pos_i - pos_j) >= block_size;
                }
            }
            return violations*(violations+1) / 40.000;
        }

    private:

        struct Sum
        {
            vector<Ptr> summands;
            char type;
        };

        bool dirty() const
        {
            if (!ans_is_cached)
            {
                return true;
            }
            if (is_atomic())
            {
                return false;
            }
            const auto& sum = get<Sum>(value);
            return any_of(sum.summands.begin(), sum.summands.end(), [](const Ptr& e) { return e->dirty(); });
        }

        double do_eval() const
        {
            // assume non-atomic.
            switch (get<Sum>(value).type)
            {
                case 'd':
                    return do_eval_helper<double>();
                case 's':
                    return do_eval_helper<float>();
                case 'h':
                    return do_eval_helper<Float16>();
                default:
                    assert(false);
            }
        }

        template<class Type>
        double do_eval_helper() const
        {
            Type acc(0.0);
            for (const auto& summand : get<Sum>(value).summands)
            {
                acc = acc + Type(summand->eval());
            }
            return double(acc);
        }

        variant<IndexFloat, Sum> value;
        mutable bool ans_is_cached;
        mutable double cached_ans;
};

////////////
// Scorer //
////////////


//class Scorer
//{
    //public:

        //Scorer(vector<double> input) : true_sum(0);
        //{
            //sort(input.begin(), input.end(), [](double x, double y)
            //{
                //return fabs(x) < fabs(y);
            //});
            //double c = 0;
            //for (double x : input)
            //{
                
            //}
        //}

    //private:

        //double true_sum;

//}


///////////////////////////
// Expression comparison //
///////////////////////////

struct GtAbs
{
    bool operator()(const Expression::Ptr& e1, const Expression::Ptr& e2) const
    {
        double abs_1 = fabs(e1->eval());
        double abs_2 = fabs(e2->eval());
        return abs_1 > abs_2;
    }
};

//////////
// Main //
//////////

int main()
{
    int N;
    cin >> N;
    vector<Expression::Ptr> X(N);
    for (int i = 0; i < N; ++i)
    {
        double float_value;
        cin >> float_value;
        X[i] = Expression::create(i+1, float_value);
    }

    if (N == 1)
    {
        X[0] = Expression::sum('s', X[0]);
    }
    
    priority_queue<Expression::Ptr,vector<Expression::Ptr>,GtAbs> q(X.begin(), X.end());

    
    while (q.size() > 1)
    {
        auto e1 = move(q.top());
        q.pop();
        auto e2 = move(q.top());
        q.pop();
        q.push(Expression::sum('s', move(e1), move(e2)));
    }

    auto top = move(q.top());
    top->print(cout, true, false);
    cout << endl;
    cout << top->eval() << endl;

    auto inorder = top->in_order();
    for (const auto&[i,f] : top->in_order())
    {
        cout << i << endl;
    }
}
