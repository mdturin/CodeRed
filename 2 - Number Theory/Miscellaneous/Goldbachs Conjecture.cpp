#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e6 + 5;
const int md = 1e9 + 7;

/**
    Goldbach’s Conjecture
        Every even integer greater than 2 can be
        expressed as the sum of two primes
*/

int mark[mx];
vector<int> prime;

inline bool is_prime(int x){
    return mark[x] == x;}

void LinearSieve(){
    mark[0] = mark[1] = -1;
    for(int i=2, j=0; i<mx; i++, j=0){
        if(!mark[i]){mark[i] = i; prime.push_back(i);}
        while(j<prime.size() && prime[j]<=mark[i] && (ll)i*prime[j]<mx)
            mark[i * prime[j]] = prime[j], j++;
    }
}

pair<int, int> get_goldbach(int x){
    assert(x>2 && x<mx);
    if(x & 1) return make_pair(-1, -1);
	for(int p : prime){
        if(p >= x) break;
		int y = x - p;
		if(y <= 1) continue;
        if(is_prime(y))
            return make_pair(p, y);
	}return make_pair(-1, -1);
}

int main(int argc, const char** argv){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    LinearSieve();

    pair<int,int> p = get_goldbach(20);
    cout << p.first << " " << p.second << "\n";

    return 0;
}
