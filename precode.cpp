/** Md. Mujahedul Azad (Turin)
Hajee Mohammad Danesh Science & Technology University(HSTU) */

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03")

#ifndef ONLINE_JUDGE
#include "dbg.hpp"
#endif

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//
//#define AT find_by_order
//#define POS order_of_key
//template<class T, class U>
//using oset = tree<T, null_type, U,
//                  rb_tree_tag,
//                  tree_order_statistics_node_update>;

#define ff              first
#define se              second
#define pb              push_back
#define MP              make_pair
#define MT              make_tuple
#define eb              emplace_back

#define SQ(x)           (x*x)
#define PF              printf
#define CB(x)           (x*x*x)
#define GC              getchar
#define INOUT           IN, OUT
#define G(a)            get<(a)>
#define SZ(x)           int(v.size())
#define Fre(i,x)        for(auto &i:x)
#define All(x)          x.begin(),x.end()
#define Clr(x)          memset(x,0,sizeof(x))
#define Set(x)          memset(x,-1,sizeof(x))
#define Fr0(i,n)        for(int i=0; i<n;  i++)
#define Fr1(i,n)        for(int i=1; i<=n; i++)
#define Fra(i,a,b)      for(int i=a; i<=b; i++)
#define IN              freopen("in","r",stdin)
#define OUT             freopen("out","w",stdout)
#define TC              for(int cs=1; cs<=tc; cs++)

#define LB(a, v)        (lower_bound(all(a), v))
#define UB(a, v)        (upper_bound(all(a), v))

#define lBit(x)         (x & (-x))
#define Sort(x)         sort(all(x))
#define sBit(x,p)       (x | (1<<p))
#define cBit(x,p)       (x & (1<<p))
#define tBit(x,p)       (x ^ (1<<p))
#define nDigit(x)       int(log10(x)+1)
#define uSet(x,p)       (x &= (~(1<<p)))
#define Max3(a,b,c)     max(a, max(b,c))
#define Min3(a,b,c)     min(a, min(b,c))
#define Abs(x)          ((x)<0?-(x):(x))
#define pTwo(x)         (x && (!(x&(x-1))))
#define Uniq(x)         Sort(x); x.erase(all(x),x.end())

using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int,int>;
using tpl = tuple<int,int,int>;

int msb(int x);
template<typename T> inline T add(T, T, T);
template<typename T> inline T sub(T, T, T);
template<typename T> inline T mul(T, T, T);
template<typename T> inline void read(T &);
template<typename T> inline T power(T, T, T);

int gcd(int a, int b){return b?gcd(b, a%b):a;}
int lcm(int a, int b){return b/gcd(a, b)*a;}
double LOG(int x, int base){return log10(x)/log10(base);}

/// first 4 directions for u, d, l, r
const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};  /** king moves */
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; /** knight moves */
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};

const int MX = 1e5 + 5;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

/// use c style
inline void solve(int &cs){
    
}

/// use c style
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
//        INOUT;
    #endif

    13.30 hour 🙂

    int tc = 1;
    read(tc); 
    TC solve(cs);

    return 0;
}

template<typename T> inline void read(T &x){
    x=0; char c=GC(), neg=0;
    while(!isdigit(c)){
        if(c=='-') neg=1; c=GC();}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c-'0'),c=GC();
    if(neg) x = 0-x;
}
template<typename T> inline T add(T a, T b, T m){return ((a%m) + (b%m))%m;}
template<typename T> inline T sub(T a, T b, T m){return (((a%m) - (b%m))%m + m)%m;}
template<typename T> inline T mul(T a, T b, T m){return ((a%m) * (b%m))%m;}
template<typename T> inline T power(T a, T p, T m){
    T ans = 1; a %= m;
    while(p > 0){
        if(p & 1) ans = mul(ans, a, m);
        a = mul(a, a, m); p >>= 1;
    }
    return ans;
}
int msb(int x){x|=(x>>1)|(x>>2)|(x>>4)|(x>>8)|(x>>16); return (x+1)>>1;}

/// Fib : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 54
/// Cat : 1, 1, 2, 5, 14, 42, 132, 429, 1430