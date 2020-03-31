#include "bits/stdc++.h"
using namespace std;

int egcd(int a, int b, int &x, int &y){
    if(a == 0) {x=0; y=1; return b;}
    int x1, y1, g = egcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1; y = x1;
    return g;
}

/** ax + by = c
    finding any x, y that state the equ.
    if there is a solution (c%gcd(a,b) == 0)
        as, ax0 + by0 = gcd(a,b);
        so, c = gcd(a,b) * k;
            k = c / gcd(a,b);
        when we find x0, y0,
            x = x0 * k; y = y0 * k;
*/

bool findAnySolution(int a, int b, int c, int &x0, int &y0, int &g){
    g = egcd(abs(a), abs(b), x0, y0);
    if(c%g != 0) return false;

    x0 *= (c/g); y0 *= (c/g);
    if(a < 0) x0 *= -1;
    if(b < 0) y0 *= -1;
    return true;
}

/**
    Geting all solutions;

    If there is a solution,
    there must be infinite solutions
        as if, ax + by = c;
        lets, add x with b/g &
              substract y with a/g,
        so,
            a(x+(b/g)) + b(y-(a/g)) = c;
            ax + by + ab/g - ab/g = c;
            ax + by = c;
        so adding b/g with x and
           substracting a/g with y gives us
           the same result.
*/

/** Number of Solutions with given interval */

int a, b, c;
void shift(int &x, int &y, int cnt){
    x += (cnt * b); y -= (cnt * a);}

int numberOfSolutions(int minx, int maxx, int miny, int maxy){
    int x, y, g;
    if(!findAnySolution(a,b,c,x,y,g))
        return 0;

    a /= g; b /= g;
    int sa = (a>0)?+1:-1;
    int sb = (b>0)?+1:-1;

    if(b != 0) shift(x, y, (minx-x)/b);
    if(x < minx) shift(x, y, sb);
    if(x > maxx) return 0;
    int lx1 = x;

    if(b != 0) shift(x, y, (maxx - x)/b);
    if(x > maxx) shift(x, y, -sb);
    int rx1 = x;

    if(a != 0) shift(x, y, -(miny-y)/a);
    if(y < miny) shift(x, y, -sa);
    if(y > maxy) return 0;
    int lx2 = x;

    if(a != 0) shift(x, y, -(maxy-y)/a);
    if(y > maxy) shift(x, y, sa);
    int rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if(lx > rx) return 0;
    if(b != 0)
        return (rx - lx)/abs(b) + 1;
    return 1;
}

/**
    Find the soluton with minimum (x+y)
    as,
        x' = x + k * b/g;
        y' = y - k * a/g;
    so,
        x' + y' = x + k * b/g + y - k * a/g;
                = x + y + k * (b-a) / g
    so if,
        a < b, k must be smallest &
        a > b, k must be largest & also
        a = b, all solution will have the same sum x+y
*/

int main(){
    int x, y, g;
    while(cin >> a >> b >> c){
        if(max(a,b) == 0){
            if(c == 0) cout << "Infinite Solutions\n";
            else cout << "No Solution\n";
        }
        else if(findAnySolution(a,b,c,x,y,g)){
            cout << x << " " << y << "\n";
            cout << "Number of Solutions in given range\n";
            int minx, maxx, miny, maxy;
            cin >> minx >> maxx >> miny >> maxy;
            if(a == 0){
                y = c/b; int cnt = (y>=miny && y<=maxy);
                cout << (maxx-minx+1)*cnt << "\n";
            } else if(b == 0){
                x = c/a; int cnt = (x>=minx && x<=maxx);
                cout << (maxy-miny+1)*cnt << "\n";
            }
            else cout << numberOfSolutions(minx, maxx, miny, maxy) << "\n";
        }
        else cout << "No Solution\n";

    }

    return 0;
}