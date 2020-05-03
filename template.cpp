/** Bismillah, ar-Rahman, ar-Rahim **
*** Giving up is the only sure way to fail ***

    Md. Mujahedul Azad (Turin)
    FB : FB/Md.turin01
    GH : GITHUB/turin1602101
    Hajee Mohammad Danesh Science & Technology University( H S T U ) */

#include<bits/stdc++.h>
using namespace std;
#define tplate template<typename T>
#define uplate template<typename T, typename U>

#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#ifndef ONLINE_JUDGE
    #include "dbg.hpp"
#endif // ONLINE_JUDGE

//#include<ext/rope>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//
//#define AT find_by_order // return iterator of index
//#define POS order_of_key // return position of value
//tplate struct pbds_cmp{
//bool operator()(const T &a, const T &b)const{
//    return a < b;}};
//
//uplate using oset = tree<T,null_type,U,rb_tree_tag,
//                        tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using vl  = vector<ll>;
using vi  = vector<int>;
using ii  = pair<int,int>;
using iii = pair<int,ii>;
using tpl = tuple<int,int,int>;

#define sq(x) ((x)*(x))
#define cb(x) ((x)*sq(x))
#define abs(x) ((x)<0?-(x):(x))

#define gp ' '
#define nl '\n'
#define ff first
#define se second
#define pf printf
#define pc putchar
#define gc getchar()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define G(a) get<(a)>
#define eb emplace_back
#define amax(a,b) a=max(a,b)
#define amin(a,b) a=min(a,b)
#define FLUSH fflush(stdout)
#define all(x) x.begin(),x.end()
#define Clr(x,sz) memset(x,0,sz)
#define Set(x,sz) memset(x,-1,sz)
#define LB(a,v) lower_bound(all(a),v)
#define UB(a,v) upper_bound(all(a),v)
#define fileIO(name)\
        freopen(name".in", "r", stdin);\
        freopen(name".out", "w", stdout)

#define Finished ld e_time=runtime
#define Starting ld s_time=runtime
#define runtime (double(clock())/CLOCKS_PER_SEC)
#define getTime cout<<(e_time-s_time)*1e3<<" ms\n"
#define precision(x) cout<<fixed<<setprecision(x)

#define For(i,a,b)  for(int i=a; i<b; i++)
#define Forn(i,a,b) for(int i=b-1; i>=a; i--)

const int INF = 0x3f3f3f3f;
const ll INFL = 0x7f7f7f7f7f7f7f;
const int MAX = INT_MAX, MIN = INT_MIN;
const double EPS = 1e-9, PI = acos(-1);
const int MOD = 1000000007, FMOD = 998244353;

tplate void read(T &val){val=0;bool neg=0;char ch=gc;
    while(ch<'0' || ch>'9'){if(ch=='-')neg=1; ch=gc;}
    while(ch>='0' && ch<='9'){val=(val*10)+(ch-'0');ch=gc;}
    if(neg)val=0-val;
}
tplate inline T gcd(T a, T b){return (b?gcd(b,a%b):a);}
tplate inline T lcm(T a, T b){return (a/gcd(a,b)*b);}
tplate inline T add(T a, T b, T c=MOD){return (a%c + b%c)%c;}
tplate inline T sub(T a, T b, T c=MOD){T r=(a-b)%c; return (r<0)?r+c:r;}
tplate inline T mul(T a, T b, T c=MOD){return ((1LL*a*b)%c);}
inline ll mulLL(ll a, ll b, ll m=MOD){
    if(b<0){b%=m; b+=m;}
    ll res=0; a%=m; b%=m;
    while(b>0){if(b & 0x1) res=add(res,a,m);
        b>>=1; a<<=1; if(a>=m) a-=m;}
    return res;
}
tplate T power(T a, T p, T m=MOD){
    if(a<0){a%=m; a+=m;} T res = 1;
    while(p>0){if(p & 0x1) res=mul<T>(res,a,m);
        p>>=1; a=mul<T>(a,a,m);}
    return res;
}
tplate T inverse(T x, T m=MOD){return power<T>(x,m-2,m);}

tplate void in(T *a, size_t n){For(i,0,n) read(a[i]);}
tplate void in(vector<T> &a, size_t n){For(i,0,n) read(a[i]);}
void outI(vi  &a, size_t n){For(i,0,n){if(i)pc(gp);printf("%d",a[i]);} puts("");}
void outI(int *a, size_t n){For(i,0,n){if(i)pc(gp);printf("%d",a[i]);} puts("");}
void outL(ll *a, size_t n){For(i,0,n){if(i)pc(gp);printf("%lld",a[i]);}puts("");}
void outL(vl &a, size_t n){For(i,0,n){if(i)pc(gp);printf("%lld",a[i]);}puts("");}

/// first 4 directions for u, d, l, r
const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};  /** king moves */
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; /** knight moves */
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};

const int mx = 1e6+10;
const int sqmx = sqrt(mx)+2;
const int lgmx = __lg(mx)+2;

int n, a[mx];

void MAIN(int cs=1){
//    printf("Case %d: ", cs);

}

int main(){

    precision(10);
    srand(time( nullptr ));

//    cin.tie( nullptr );
//    ios_base::sync_with_stdio(0);

    int tc = 1;
    read(tc);
    For(i,1,tc+1)
        MAIN(i);

    return 0;
}

/// Fib : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 54
/// Cat : 1, 1, 2, 5, 14, 42, 132, 429, 1430
