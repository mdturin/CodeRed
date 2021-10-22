#include "bits/stdc++.h"
using namespace std;

template<typename TYPE>
void merge(TYPE a[], size_t lw, size_t mid, size_t hh){
    TYPE b[hh - lw + 1]; size_t i, j, k=0;
    for(i=lw,j=mid+1; i<=mid && j<=hh;)
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    while(i<=mid) b[k++] = a[i++];
    while(j<=hh) b[k++] = a[j++];
    for(size_t kk=0; kk<k; kk++)
        a[lw+kk] = b[kk];
}

template<typename TYPE>
void mergesort(TYPE a[], size_t lw, size_t hh){
    if(lw < hh){
        int mid = (lw+hh)/2;
        mergesort(a, lw, mid);
        mergesort(a, mid+1, hh);
        merge(a, lw, mid, hh);
    }
}

int main(int argc, const char** argv) {
    srand(time(0));

    int n = rand() % 10;
    int a[n] = {};

    for(int i=0; i<n; i++)
        a[i] = rand() % 100; 
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << "\n";
    
    mergesort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << "\n\n\n";

    return 0;
}