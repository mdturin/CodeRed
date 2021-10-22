#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using tpl = tuple<int,int,int>;

#define AT find_by_order // return iterator of index
#define POS order_of_key // return position of value
#define ERS(st,x) (st).erase((st).AT((st).POS((x)))) // Erase x value
using oset = tree<int, null_type, less_equal<int>,
                    rb_tree_tag, tree_order_statistics_node_update>;

const int mx = 1e6 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<tpl> vec;
        int d, l, c; string s;
        for(int i=0; i<n; ++i){
            cin >> d >> l >> s;
            c = (s[0] == 'c');
            vec.emplace_back(d, l, c);
        }sort(vec.begin(), vec.end());

        long long ans = 0; oset st;
        for(auto it : vec){
            tie(d, l, c) = it;
            if(l == 1 && c == 1)
                ans += st.POS(d);
            else if(l==0 && c==0)
                st.insert(d);
        }cout << ans << "\n";
    }

    return 0;
}

