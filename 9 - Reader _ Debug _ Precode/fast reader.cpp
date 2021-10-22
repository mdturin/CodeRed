#include "bits/stdc++.h"
using namespace std;

template<typename TYPE>
void read(TYPE &x){
    x = 0; int sign = 1;
    int c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') sign = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<3)+(x<<1) + (c-'0');
        c = getchar();
    }
    x = x * sign;
}

int main(int argc, const char** argv) {
    return 0;
}