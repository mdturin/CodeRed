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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, x, y, g;
    while(cin >> a >> b >> c){
        if(has_solution(a, b, c, x, y, g))
            cout << x << " " << y << "\n";
        else cout << "no solution exist\n";
    }

    return 0;
}
