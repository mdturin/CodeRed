#include<bits/stdc++.h>
using namespace std;
const int mx  = 2e5 + 5;

int n, a[mx];
int pre[mx], tail[mx];

int get_pos(int x, int len){
    int lw = -1, hh = len - 1;
    while(hh - lw > 1){
        int m = lw + (hh - lw) / 2;
        if(a[tail[m]] >= x) hh = m;
        else lw = m;
    }return hh;
}

inline int solve(){
    memset(pre, -1, sizeof pre);
    memset(tail, 0, sizeof tail);

    int len = 1;
    for(int i=1; i<n; i++){
        if(a[i] < a[tail[0]]) tail[0] = i;
        else if(a[i] > a[tail[len-1]]){
            pre[i] = tail[len-1];
            tail[len++] = i;
        }else{
            int p = get_pos(a[i], len);
            pre[i] = tail[p-1]; tail[p] = i;
        }
    }return len;
}

vector<int> LIS(){
    int len = solve(), j = len-1;
    vector<int> res(len);
    for(int i=tail[len-1]; i>=0; i=pre[i])
        res[j] = a[i], j--;
    return res;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<int> res = LIS();
    cout << res.size() << "\n";
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " \n"[i+1==res.size()];

    return 0;
}

