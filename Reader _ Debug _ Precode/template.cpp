#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
using ii  = pair<int,int>;
using tpl = tuple<int,int,int>;

#define IL inline
#define TP template<class T>
#define UP template<class T, class U>
#define HP template<class H, class...T>

#pragma GCC target("avx,avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

/******* PBDS *********/
#define AT find_by_order // return iterator of index
#define POS order_of_key // return position of value
#define ERS(st,x) (st).erase((st).AT((st).POS((x)))) // Erase x value
TP struct pbds_cmp{bool operator()(const T &a, const T &b)const{return a < b;}};
UP using oset = tree<T, null_type, U, rb_tree_tag, tree_order_statistics_node_update>;

#define gp ' '
#define nl '\n'
#define ff first
#define se second
#define pf printf
#define pc putchar
#define gc getchar()
#define pb push_back
#define mt make_tuple
#define LB lower_bound
#define UB upper_bound
#define eb emplace_back
#define SQ(x) ((x)*1LL*(x))
#define CB(x) ((x)*SQ((x)))
#define amax(a,b) a=max(a,b)
#define amin(a,b) a=min(a,b)
#define FLUSH fflush(stdout)
#define G(t, a) get<(a)>((t))
#define all(x) (x).begin(),(x).end()
#define Clr(x) memset((x),  0, sizeof((x)))
#define Set(x) memset((x), -1, sizeof((x)))
#define fileIO(name)\
        freopen(name".in", "r", stdin);\
        freopen(name".out", "w", stdout)
#define For(i,a,b)  for(int i=a;  i<b; i++)
#define Forn(i,b,a) for(int i=b; i>=a; i--)

IL bool read(char&); IL bool read(char*);
IL void write(char); IL void write(char*);
TP IL bool read(T&); HP IL bool read(H&,T&...);
IL void write(const char*); HP IL void write(H,T...); TP IL void write(T);

TP void in(T *a, size_t n){For(i,0,n) read(a[i]);}
TP void in(vector<T> &a, size_t n){For(i,0,n) read(a[i]);}
void out(vi  &a, size_t n){For(i,0,n){if(i)pc(gp);write(a[i]);}puts("");}
void out(int *a, size_t n){For(i,0,n){if(i)pc(gp);write(a[i]);}puts("");}
void out( ll *a, size_t n){For(i,0,n){if(i)pc(gp);write(a[i]);}puts("");}
void out( vl &a, size_t n){For(i,0,n){if(i)pc(gp);write(a[i]);}puts("");}

const int INF = 0x3f3f3f3f;
const ll INFL = 0x7f7f7f7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);
const int MOD = 1e9+7, MODF = 998244353;

/** Necessary Function **/
TP IL T power(T v, T p, T m=MOD) {
    v %= m; T r = 1; while (p > 0) {
        if (p & 0x1) r = (r*1LL*v)%m;
        v = (v*1LL*v)%m; p >>= 1;
    }return r;
}
IL void No(){write("NO\n"); exit(0);}
IL void Yes(){write("YES\n"); exit(0);}
TP IL T gcd(T a, T b){return (b?gcd(b,a%b):a);}
TP IL T lcm(T a, T b){return (a / gcd(a,b) * b);}
TP IL T inv(T x, int m=MOD){return power<T>(x, m-2, m);}
TP IL T lowestSetBit(T x){return (x & (-x));}
TP IL void setBit(T &x, int p){x |= (1LL<<p);}
TP IL T highestSetBit(T x){return (1LL<<(__lg(x)));}
TP IL bool isSet(T x, int p){return x & (1<<p);}
TP IL void toggleBit(T &x, int p){x ^= (1LL<<p);}
TP IL void unsetBit(T &x, int p){x &= (~(1LL<<p));}
IL bool isPowerOfTwo(ll x){return x && (!(x & (x-1)));}
IL int numberOfSetBit(ll x){return __builtin_popcountll(x);}

/// First 4 Directions are U, D, L, R
const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1},  dy[] = {0, 0, -1, 1, 1, 1, -1, -1};  /** king moves */
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; /** knight moves */

const int mx = 2e6+5;
const int sqmx = sqrt(mx)+2, lgmx = __lg(mx)+2;

char buf[mx];
int n, a[mx];

inline void solve(int cs){
//    write("Case ", cs, ": ");

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int tc = 1; srand(time(nullptr));

//    read(tc);

    for(int cs=1; cs<=tc; cs++)
        solve(cs);
    return 0;
}

/// Fib : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 54
/// Cat : 1, 1, 2, 5, 14, 42, 132, 429, 1430

char os[100]; IL void write(char c){pc(c);} IL void write(char *s){pf("%s",s);} IL void write(const char *s){pf("%s",s);} HP IL void write(H h, T ...t){write(h);write(t...);} TP IL void write(T x) {if(x==0) {pc('0');return;}int i=0;bool neg=(x<0);if(neg)pc('-'),x=-x;while(x>0) {os[i++]=(x%10)+'0';x/=10;}i--;while(i>=0) pc(os[i--]);}
IL bool read(char &c) {c=gc;return c!=EOF;} IL bool read(char *s){return scanf("%s",s);} HP IL bool read(H& h, T&... t) {return read(h)&&read(t...);} TP IL bool read(T &val) {val=0;bool neg=0;char ch=gc;while(ch <'0' || ch >'9') {if(ch=='-') neg=1;else if(ch==EOF)return 0;ch=gc;}while(ch>='0' && ch<='9') {val=(val*10)+(ch-'0');ch=gc;}if(neg)val=-val;return 1;}
