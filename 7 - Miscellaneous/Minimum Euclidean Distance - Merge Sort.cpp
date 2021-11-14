#include<bits/stdc++.h> 
using namespace std; 
using ll = long long; 
using vi = vector<int>; 
using ii = pair<int, int>;

#define SQ(x) ((x) * (x)) 
const int md = 1e9 + 7; 
const int mx = 2e5 + 5; 
 
struct Point{
    ll x, y;
    Point() = default;
    Point(ll _x) : x(_x), y(_x){}
    Point(ll _x, ll _y) : x(_x), y(_y){}

    Point operator + (const Point &ot) const {return Point(x + ot.x, y + ot.y);}
    Point operator - (const Point &ot) const {return Point(x - ot.x, y - ot.y);}

    long long cross(const Point &p) const{return x * p.y - y * p.x;}
    long long cross(const Point &a, const Point &b) const{
        return (a-*this).cross(b-*this);}

    inline void read(){cin >> x >> y;}
    inline void write(){cout << "(" << x << ", " << y << ")";}
}P[mx];

inline bool cmpX(Point p, Point q){
    if(p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

inline bool cmpY(Point p, Point q){
    if(p.y != q.y) 
        return p.y < q.y; 
    return p.x < q.x;
}

ll get_dist(Point p, Point q){
    return SQ(p.x - q.x) + SQ(p.y - q.y);}

ll fun(int l, int r){
    ll ans = 9e18;
    for(int i=l; i<=r; ++i)
    for(int j=i+1; j<=r; ++j)
        ans = min(ans, get_dist(P[i], P[j]));
    return ans;
}

ll solve(vector<Point> &a, ll ans){
    sort(a.begin(), a.end(), cmpY);
    int n = a.size();
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n && (a[j].y - a[i].y)<ans; ++j)
                ans = min(ans, get_dist(a[i], a[j]));
    return ans;
}

inline ll solve(int l, int r){
    int n = r - l + 1;
    if(n == 1) return 9e18;
    if(n == 2) return get_dist(P[l], P[r]);
    if(n <= 4) return fun(l, r);
    
    int mid = (l + r) / 2;    
    ll L = solve(l, mid);
    ll R = solve(mid+1, r);

    vector<Point> NP;
    ll ans = min(L, R);

    // nth_element(P, P+mid+1, P+n, cmpX);
    for(int i=l; i<=r; ++i)
        if(abs(P[i].x - P[mid].x) < ans)
            NP.push_back(P[i]);

    ll res = solve(NP, ans);
    return min(ans, res);
}

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr); 
 
    int n; cin >> n;
    for(int i=0; i<n; ++i) 
        P[i].read();

    sort(P, P + n, cmpX);
    cout << solve(0, n-1) << "\n";
 
    return 0; 
} 