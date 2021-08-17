#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 5;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_month_id(string s){
    if(s == "JAN") return 0;
    if(s == "FEB") return 1;
    if(s == "MAR") return 2;
    if(s == "APR") return 3;
    if(s == "MAY") return 4;
    if(s == "JUN") return 5;
    if(s == "JUL") return 6;
    if(s == "AUG") return 7;
    if(s == "SEP") return 8;
    if(s == "OCT") return 9;
    if(s == "NOV") return 10;
    if(s == "DEC") return 11;
    return 0;
}

int get_day_id(string s){
    if(s == "SUN") return 0;
    if(s == "MON") return 1;
    if(s == "TUE") return 2;
    if(s == "WED") return 3;
    if(s == "THU") return 4;
    if(s == "FRI") return 5;
    if(s == "SAT") return 6;
    return 0;
}

int get_days(string s){
    int m = get_month_id(s);
    return days[m];
}

/**
3
JAN SUN
FEB SUN
OCT THU
*/

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    string mon, day_str;
    while(tc--){
        cin >> mon >> day_str;
        int tot_days = get_days(mon);
        int rem = tot_days % 7;

        int ans = 8;
        int day = get_day_id(day_str);
        for(int i=day; i<day+rem; ++i)
            if((i%7) >= 5) ans++;

        cout << ans << "\n";
    }

    return 0;
}

