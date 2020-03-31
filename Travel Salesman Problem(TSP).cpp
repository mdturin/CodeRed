#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;

int dp[16][4];
int VISITED_ALL = (1<<n) - 1;

int n = 4, src = 0;
int dist[10][10] = {
        {0,20,42,35},
        {20,0,30,34},
        {42,30,0,12},
        {35,34,12,0}
};

int tsp(int mask, int pos){
    if(mask == VISITED_ALL) return dist[pos][src];
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for(int i=0; i<n; i++)
        if(!(mask & (1 << i))){
            int newAns = dist[pos][i] + tsp(mask|(1<<i), i);
            ans = min(ans, newAns);
        }

    return dp[mask][pos] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    cout << tsp(1, src) << '\n';
    return 0;
}