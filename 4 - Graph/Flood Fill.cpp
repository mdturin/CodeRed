#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

#define ff first
#define se second

const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

const int mx = 1e3 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
string grid[mx];

inline bool valid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;}

int flood_fill(int r, int c, char c1, char c2){
    if(!valid(r, c)) return 0;
    if(grid[r][c] != c1) return 0;

    int ans = 1; grid[r][c] = c2;
    for(int i=0; i<8; i++){
        int rr = r + dx[i], cc = c + dy[i];
        ans += flood_fill(rr, cc, c1, c2);
    }return ans;
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
