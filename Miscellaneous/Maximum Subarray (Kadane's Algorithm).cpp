#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct max_sub_array{
    long long best;
    size_t _start, _end;
    long long solve(T a[], size_t n){
        _start = _end = 0;
        long long cur=0; best=-1e16;
        for(int i=0; i<n; i++){
            if(a[i] > cur+a[i])
                _start=i, cur=a[i];
            else cur += a[i];
            if(best < cur)
                best = cur, _end = i;
        }return best;
    }
    pair<int,int> get_limits(){
        return pair<int,int>(_start, _end);
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[] = {-1, 7, 8, -6, 8, -21, 12, 3};
    int n = sizeof(a)/4;

    max_sub_array<int> solver;
    cout << solver.solve(a, n) << "\n";

    return 0;
}
