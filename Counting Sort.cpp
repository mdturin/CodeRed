#include "bits/stdc++.h"
using namespace std;

// Complexity O(n + mx)
void countingSort(int a[], int n){
    int mx = *max_element(a, a+n) + 1;
    vector<int> cnt(mx, 0);
    for(int i=0; i<n; i++) cnt[a[i]]++;
    for(int j=0, i=0; i<mx; i++)
        for(int k=0; k<cnt[i]; k++)
            a[j++] = i;
}

int main(int argc, const char** argv) {
    srand(time(0));

    int n = rand() % 25;
    int a[n] = {};

    for(int i=0; i<n; i++)
        a[i] = rand() % 100; 
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << "\n";
    
    countingSort(a, n);
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << "\n\n\n";

    return 0;
}