#include<bits/stdc++.h> 
using namespace std; 
using ll = long long; 
using vi = vector<int>; 
using ii = pair<int, int>; 
 
#define SQ(x) ((x) * (x))
const int md = 1e9 + 7; 
const int mx = 1e6 + 5; 
 
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

ll get_dist(Point a, Point b){
    return SQ(a.x - b.x) + SQ(a.y - b.y);}

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

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr); 
 
    int n; cin >> n;
    for(int i=0; i<n; ++i)
        P[i].read();
    sort(P, P+n, cmpX);

    set<Point, decltype(&cmpY)> st(&cmpY);
    
    st.insert(P[0]); 
    ll ans = LLONG_MAX;
    for(int i=1, j=0; i<n; ++i){
        auto it = st.begin();
        ll res = sqrtl(ans);
        while(j<i && P[i].x-P[j].x > res)
            st.erase(P[j]), j++;
        
        auto l = st.lower_bound({0, P[i].y-res});
        auto r = st.upper_bound({0, P[i].y+res});
        for(auto it = l; it != r; it++)
            ans = min(ans, get_dist(*it, P[i]));

        st.insert(P[i]);
    } 

    cout << ans << "\n"; 
    return 0; 
} 