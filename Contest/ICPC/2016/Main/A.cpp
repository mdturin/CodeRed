#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

set<int> st = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561,
            2985984, 4826809, 7529536, 11390625, 16777216, 24137569,
            34012224, 47045881, 64000000, 85766121};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; while(cin >> n, n){
        if(st.count(n))
            cout << "Special\n";
        else cout << "Ordinary\n";
    }

    return 0;
}

