#include "bits/stdc++.h"
using namespace std;

const int mx = 1e3+5;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

int R, C;
char grid[mx][mx];

int floodFill(int r, int c, char c1, char c2){
    if(r<0 || r>=R || c<0 || c>=C) return 0;
    if(grid[r][c] != c1) return 0;

    int ans = 1;
    grid[r][c] = c2;
    for(int i=0; i<8; i++){
        int rr = r + dx[i];
        int cc = c + dy[i];
        ans += floodFill(rr, cc, c1, c2);
    }
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}