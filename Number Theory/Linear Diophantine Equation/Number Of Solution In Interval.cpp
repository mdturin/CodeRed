#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

// extended GCD
ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){x=1; y=0; return a;}
    ll xx, yy, g = egcd(b, a%b, xx, yy);
    y = xx - (a / b) * yy; x = yy;
    return g;
}

bool has_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g){
    g = egcd(abs(a), abs(b), x, y);
    if(abs(c)%g) return false;
    x *= (c/g); if(a<0) x *= -1;
    y *= (c/g); if(b<0) y *= -1;
    return true;
}

ll a, b, c;
inline void shift(ll &x, ll &y, ll cnt){
    x += (cnt * b); y -= (cnt * a);}

ll solutions(ll minx, ll maxx, ll miny, ll maxy){
    ll x, y, g;
    if(!has_solution(a,b,c,x,y,g))
        return 0;

    a /= g; b /= g;
    int sa = (a>0) ? 1 : -1;
    int sb = (b>0) ? 1 : -1;

    if(b != 0) shift(x, y, (minx-x)/b);
    if(x < minx) shift(x, y, sb);
    if(x > maxx) return 0;
    ll lx1 = x;

    if(b != 0) shift(x, y, (maxx - x)/b);
    if(x > maxx) shift(x, y, -sb);
    ll rx1 = x;

    if(a != 0) shift(x, y, -(miny-y)/a);
    if(y < miny) shift(x, y, -sa);
    if(y > maxy) return 0;
    ll lx2 = x;

    if(a != 0) shift(x, y, -(maxy-y)/a);
    if(y > maxy) shift(x, y, sa);
    ll rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);
    if(lx > rx) return 0;
    if(b != 0)
        return (rx - lx)/abs(b) + 1;
    return 1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, g, minx, maxx, miny, maxy;
    while(cin >> a >> b >> c){
        cin >> minx >> maxx >> miny >> maxy;
        if(a == 0 && b == 0){
            if(c == 0)
                cout << "Infinite Solutions\n";
            else cout << "No Solution\n";
        }else if(has_solution(a,b,c,x,y,g)){
            if(a == 0){
                y = c / b;
                int cnt = (y>=miny && y<=maxy);
                cout << (maxx-minx+1) * cnt << "\n";
            }else if(b == 0){
                x = c / a;
                int cnt = (x>=minx && x<=maxx);
                cout << (maxy-miny+1) * cnt << "\n";
            }else cout << solutions(minx, maxx, miny, maxy) << "\n";
        }else cout << "No Solution\n";
    }

    return 0;
}
