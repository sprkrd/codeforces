#include <bits/stdc++.h>
using namespace std;


typedef pair<int,double> IndexFloat;


class Expression
{
    public:

        typedef shared_ptr<Expression> Ptr;
        typedef tuple<Ptr,Ptr,char> Sum;

        static Ptr create(int i, double float_value)
        {
            return make_shared<Expression>(IndexFloat(i, float_value));
        }

        static Ptr sum(Ptr l, Ptr r, char type = 'd')
        {
            return make_shared<Expression>(move(l), move(r), type);
        }

        Expression(const IndexFloat& value) : value(value), ans_is_cached(true), cached_ans(value.second)
        {
        }

        Expression(Ptr l, Ptr r, char type = 'd') : value(Sum{l,r,type}), ans_is_cached(false)
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

        const Sum& get_sum() const
        {
            return get<Sum>(value);
        }

        char sum_type() const
        {
            return get<2>(get<Sum>(value));
        }

        void set_sum_type(char type)
        {
            get<2>(get<Sum>(value)) = type;
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
                const auto&[l,r,type] = get_sum();
                out << '{' << type << ':';
                l->print(out, use_indices, false);
                out << ',';
                r->print(out, use_indices, false);
                out << '}';
            }
            if (print_nl)
            {
                out << '\n';
            }
        }

    private:

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
            const auto&[l,r,type] = get_sum();
            return l->dirty() || r->dirty();
        }

        double do_eval() const
        {
            // assume non-atomic, for the time being type is ignored.
            const auto&[l,r,type] = get_sum();
            return l->eval() + r->eval();
        }

        variant<IndexFloat, Sum> value;
        mutable bool ans_is_cached;
        mutable double cached_ans;
};

struct GtAbs
{
    bool operator()(const Expression::Ptr& e1, const Expression::Ptr& e2) const
    {
        double abs_1 = fabs(e1->eval());
        double abs_2 = fabs(e2->eval());
        return abs_1 > abs_2;
    }
};

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
        cout << "{d:";
        X[0]->print(cout, true, false);
        cout << '}' << endl;
        return 0;
    }
    
    priority_queue<Expression::Ptr,vector<Expression::Ptr>,GtAbs> q(X.begin(), X.end());

    
    while (q.size() > 1)
    {
        auto e1 = move(q.top());
        q.pop();
        auto e2 = move(q.top());
        q.pop();
        q.push(Expression::sum(move(e1), move(e2)));
    }

    auto top = move(q.top());
    top->print(cout, true, false);
    cout << endl;
}
