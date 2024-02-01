#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int mx = 1e3 + 5;
const int inf = 0x3f3f3f3f;

#define ff first
#define se second

/// first 4 directions are LURD
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};

/// knight moves
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dist[mx][mx];
int n, m, vis[mx][mx];

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);}

void bfs(int sx, int sy){
    for(int i=0; i<mx; ++i)
        fill(dist[i], dist[i]+mx, inf);

    queue<ii> q;
    q.push(ii(sx, sy));
    dist[sx][sy] = 0;

    int x, y; while(q.size()){
        tie(x, y) = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(valid(xx, yy) && dist[xx][yy]==inf){
                dist[xx][yy] = dist[x][y] + 1;
                q.push(ii(xx, yy));
            }
        }
    }
}

int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bfs(1, 1);

    return 0;
}
