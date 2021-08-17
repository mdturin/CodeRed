#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int get_value(char c){
    if(isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int convert(string s, int base){
    int ans = 0, k = 1;
    for(int i=s.size()-1; i>=0; --i, k*=base)
        ans += get_value(s[i]) * k;
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; int x, y, q;
    while(cin >> s >> q, q){
        if(s[0] == '0'){
            if(s[1] == 'x')
                x = convert(s.substr(2), 16);
            else x = convert(s.substr(1), 8);
        }else x = stoi(s);

//        cout << x << "\n";

        int ans = 0; while(q--){
            cin >> s >> y;
            if(s.size() == 3){
                if(s[0] == '+') ans += (x+1 == y);
                else if(s[0] == '-') ans += (x-1 == y);
                else ans += (x == y);
            }else if(x == y) ans++;

            x = y;

            if(s.size() == 3){
                if(s.back() == '+') x++;
                else if(s.back() == '-') x--;
            }
        }cout << ans << "\n";
    }

    return 0;
}

