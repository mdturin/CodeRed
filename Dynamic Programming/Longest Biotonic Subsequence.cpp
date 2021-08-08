/**
    longest biotonic subsequence
    a subsequence of arr[] is called
    Biotonic if it is first increasing, then decreasing
*/

#include<bits/stdc++.h>
using namespace std;
const int mx  = 2e5 + 5;

int n, a[mx];
int inc[2][mx], tail[2][mx];

int get_pos(int x, int p, int len){
    int lw = 0, hh = len-1, ans = -1;
    while(lw <= hh){
        int m = (lw + hh) / 2;
        if(inc[p][m] >= x)
            ans = m, hh = m - 1;
        else lw = m + 1;
    }return ans;
}

int solve(int p){
    inc[p][0] = a[0];
    int len = 1; tail[p][0] = 0;
    for(int i=1; i<n; i++){
        if(a[i] < inc[p][i])
            tail[p][0] = 0, inc[p][0] = a[i];
        else if(inc[p][len-1] < a[i])
            tail[p][i] = len, inc[p][len++] = a[i];
        else{
            int pp = get_pos(a[i], p, len);
            tail[p][i] = pp, inc[p][pp] = a[i];
        }
    }return len;
}

int LBS_Utill(){
    solve(0);
    reverse(a, a+n);

    solve(1);
    reverse(a, a+n);
    reverse(tail[1], tail[1] + n);

    int ans = 0, pos = 0;
    for(int i=0; i<n; i++)
        if(ans < tail[0][i]+tail[1][i]+1)
            ans = tail[0][i]+tail[1][i]+1, pos = i;
    return pos;
}

inline vector<int> LBS(){
    int p = LBS_Utill();
    vector<int> res(1, p);
    for(int i=p-1; i>=0; i--)
        if(tail[0][i]+1 == tail[0][res.back()])
            res.push_back(i);
    reverse(res.begin(), res.end());
    for(int i=p+1; i<n; i++)
        if(tail[1][i]+1 == tail[1][res.back()])
            res.push_back(i);
    return move(res);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<int> res = LBS();
    cout << res.size() << "\n";
    for(int i=0; i<res.size(); ++i)
        cout << a[res[i]] << " \n"[i+1==res.size()];

    return 0;
}

