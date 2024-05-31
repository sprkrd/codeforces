#include<bits/stdc++.h>
#define maxn 2900001
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
using namespace std;
int T,n,a[maxn],b[maxn];
bool judge(){
	a[0]=-1,a[n+1]=-1;
	for(int i=1;i<=n;i++)
	 if(i!=n&&a[i]/2!=a[i+1]&&a[i]!=a[i+1]/2) return 0;
	 else if(a[i]!=b[i]&&b[i]!=-1) return 0;
	return 1;
}
void solve(){
	scanf("%d",&n);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	while(a[l]==-1&&l<=r) l++;
	while(a[r]==-1&&l<=r) r--;
	if(l>r){
		for(int i=1;i<=n;i++) printf("%d ",(i-1)%2+1);
		puts("");
		return;
	}
	for(int i=l-1;i>=1;i--)
	 if((l-i)&1) a[i]=a[i+1]*2;
	 else a[i]=a[i+1]/2;
	for(int i=r+1;i<=n;i++)
	 if((i-r)&1) a[i]=a[i-1]*2;
	 else a[i]=a[i-1]/2;
	for(int i=l;i<r;i++){
		int j=i+1;
		while(a[j]==-1&&j<=r) j++;
		int x=a[i],y=a[j],ii=i+1,iii,jj=j-1;
		int len=log2(x),lenn=log2(y);
		while(len<lenn&&ii<=jj) a[jj--]=(y>>=1),lenn--;
		while(len>lenn&&ii<=jj) a[ii++]=(x>>=1),len--;
		while(x!=y&&ii<=jj) a[ii++]=(x>>=1),a[jj--]=(y>>=1);
		iii=ii;
		while(ii<=jj)
		 if((ii-iii)%2==0) a[ii++]=(a[ii-1]<<1);
		 else a[ii++]=(a[ii-1]>>1);
		i=j-1;
	}
	if(!judge()) return puts("-1"),void();
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
}
signed main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

