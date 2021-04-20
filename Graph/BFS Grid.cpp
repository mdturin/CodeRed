#include "bits/stdc++.h"
using namespace std;

/// first 4 directions are LURD
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};

/// knight moves
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[] = {-2, -1, 1, 2, 2, 1, -1, -2};

const int MX = 1e3+5;
const int INF = 1e9+9;

int n, m;
int vis[MX][MX];
int dist[MX][MX];

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);}

void bfs(int sx, int sy){
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    queue<int> qx; qx.push(sx);
    queue<int> qy; qy.push(sy);
    vis[sx][sy] = 1;

    while(qx.size()){
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        for(int i=0; i<8; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(valid(xx, yy)){
                vis[xx][yy] = 1;
                dist[xx][yy] = dist[x][y]+1;
                qx.push(xx); qy.push(yy);
            }
        }
    }
}

int main(int argc, const char** argv) {

    return 0;
}