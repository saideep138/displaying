#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(long i = 0; i < (n); ++i)
#define repA(i, a, n)  for(long i = a; i <= (n); ++i)
#define repD(i, a, n)  for(long i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll one=1;
const ll zero=0;
map<int,int, greater<int>> nums;
void pre()
{

}
int p;
signed long long solve()
{
    ll k,m;int n;cin>>n>>m;p = 1;
    //rep(i,n)cin>>arr[i];
    //int nums[66];fill(nums);
    //map<long long, int, greater<long long>> inc;
    rep(i,60) nums[i] = zero;

    rep(i,n)
    {
    	long long t ;cin>>t;// arr[i] = t ;
    	int pos = 0 ;
    	while(t>zero)
    	{
    		nums[pos]+=t&(one) ;
    		pos++ ;
    		t = t>>1 ;	//t >>= 1;
    	}
    }

    int maxl ;
    repD(i,59,0){
    	if(nums[i]!=0){
    		maxl = i;break;
    	}
    }
    
    int ans[59];fill(ans);
    long long ext[59];fill(ext);
    repA(i,0,maxl){
    	if(nums[i]>=(n-nums[i]))	//	number of 1's >= number of 0's 
    		{
    			m -= ((ll)n-nums[i])<<i ;
    			ans[i] = 1;
    		}
    	else{
    			ext[i] = ((ll)n - nums[i]*2)<<i;
    			m -= ((ll)(nums[i]))<<i ;
    		}
    	}
if(m<zero){
	p = 11;
	return 5;
}
long long  val = zero ;
    repD(i,maxl,0){
    	if(ans[i]==0	&&	m-ext[i]>=zero)
    	{
    		m -= ext[i];
    		ans[i] = 1;
    	}
    	if(ans[i]==1)
    	{
    		val += one<<i;
    	}
    }
    if(m>zero)
    {
    	maxl++;
    	
    	while((m-((ll)n*(one<<maxl)))>=zero)
    	{
    		m -= (ll)n*(one<<maxl);
    		val += one<<maxl;
    		maxl++;
    	}
    }

    return val;


}
int main() 
{
    cin.sync_with_stdio(0); cin.tie(0);//cout.tie(0);
    cin.exceptions(cin.failbit);
    pre();
    //code here
    int n;cin>>n;
    rep(i,n) {
    	signed long long val;
    	val = solve();
    	if(p==1)
    	cout<<"Case #"<<i+1<<": "<<val<<'\n';
    	else
    	cout<<"Case #"<<i+1<<": -1"<<'\n';    
    }
    return 0;
}

