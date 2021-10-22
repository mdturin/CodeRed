#include "bits/stdc++.h"
using namespace std;

struct node{
    int a, b, c;
    node(){}
    node(int _a, int _b, int _c):
        a(_a), b(_b), c(_c){}
    bool operator < (const node &ot){
        if(c != ot.c) return c < ot.c;
        if(b != ot.b) return b < ot.b;
        if(a != ot.a) return a < ot.a;
    }
    bool operator == (const node &ot){
        return a==ot.a && b==ot.b && c==ot.c;}
    void print(){cout << a << ' ' << b << ' ' << c << '\n';}
};

template<typename TYPE>
TYPE *partition(TYPE *s, TYPE *e){
    TYPE *p=s, *lw=s, *hh=e-1;
    while(lw < hh){
        while(  *lw<*p || *lw==*p)  lw++;
        while(!(*hh<*p || *hh==*p)) hh--;
        if(lw < hh) swap(*lw, *hh);
    }
    swap(*p, *hh);
    return hh;
}

template<typename TYPE>
void quicksort(TYPE *s, TYPE *e){
    if(s+1 < e){
        TYPE *p = partition(s, e);
        quicksort(s, p);
        quicksort(p+1, e);
    }
}

int main(int argc, const char** argv) {
    srand(time(0));

    // int n = rand() % 25;
    // int a[n] = {};

    // for(int i=0; i<n; i++)
    //     a[i] = rand() % 100; 
    // for(int i=0; i<n; i++)
    //     cout << a[i] << ' ';
    // cout << "\n";
    
    // quicksort(a, a+n);
    // for(int i=0; i<n; i++)
    //     cout << a[i] << ' ';
    // cout << "\n\n\n";

    int n = rand() % 100;
    node ara[n];
    for(int i=0; i<n; i++){
        int a = rand() % 10;
        int b = rand() % 10;
        int c = rand() % 10;
        ara[i] = node(a, b, c);
    }
    quicksort(ara, ara+n);

    for(int i=0; i<n; i++)
        ara[i].print();

    return 0;
}