#include<bits/stdc++.h>
using namespace std;
#define tplate template<typename T>
#define hplate template<typename A, typename... B>

namespace io{int f, qr;
    const int SZ=(1<<21)+1;
    char ibuf[SZ], *is, *it;
    char obuf[SZ], *os = obuf;
    char *ot = os + SZ - 1, c, qu[55];
    #define gc ((is==it) ? it=(is=ibuf)+fread(ibuf,1,SZ,stdin),\
               ((is==it) ? EOF : *is++) : *is++)

    inline void flush(){fwrite(obuf,1,os-obuf,stdout);os=obuf;}
    inline void putc(char c){*os++=c;if(os==ot)flush();}
    tplate inline bool read(T &x){
        for(f=0,c=gc; c<'0'||c>'9'; c=gc)
            if(c=='-') f=-1; else if(c==EOF) return 0;
        for(x=0; c>='0'&&c<='9'; c=gc) x=(x*10)+(c&15);
        if(f) x=0-x; return 1;}
    inline bool read(char &c){
        while((c=gc)==' '||c=='\n'||c=='\r'); return c!=EOF;}
    inline bool read(char *s){
        while((*s=gc)=='\n' || *s==' ' || *s=='\r'); if(*s==EOF)return 0;
        while(!((*s=gc)=='\n' || *s==' ' || *s=='\r')) *(++s) = gc;
        *s = 0; return 1;}
    hplate inline bool read(A &x, B &...y){return read(x)&&read(y...);}
}
//using io :: read; using io :: putc;

template<typename T>
inline void read(T &val){
    #define gc getchar()
    val=0;bool neg=0;char ch=gc;
    while(ch <'0' || ch >'9'){if(ch=='-')neg=1; ch=gc;}
    while(ch>='0' && ch<='9'){val=(val*10)+(ch-'0');ch=gc;}
    if( neg ) val = 0 - val;
}

const int mx = 1e7;
long long xorShift64s(int x){
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 2685821657736338717LL;
}

void cinTest(){
    long long x;
    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> x;
}

void cinTestFasterIO(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    long long x;
    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> x;
}

void scanfTest(){
    long long x;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lld", &x);
}

void scanfTestFasterIO(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    long long x;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lld", &x);
}

void fasterRead(){
    long long x;
    int n; read(n);
    for(int i=0; i<n; i++)
        read(x);
}

void fasterReadBuff(){
    long long x;
    int n; io::read(n);
    for(int i=0; i<n; i++)
        io::read(x);
}

int main(){
    srand(time(nullptr));
//    freopen("in", "w", stdout);
    freopen("in", "r", stdin);

//    cout << mx << '\n';
//    for(int i=0; i<mx; i++)
//        cout << xorShift64s(rand()) << "\n";

//    cinTest();
//    cinTestFasterIO();
//    scanfTest();
//    scanfTestFasterIO();
//    fasterRead();
    fasterReadBuff();

    return 0;
}

/**
Benchmark

          type      -       limit       -       time(s)
cin                 -        1e5        -       0.112
cin Faster          -        1e5        -       0.039
scanf               -        1e5        -       0.033
scanf Faster        -        1e5        -       0.030
fast reader         -        1e5        -       0.019
fast reader (fread) -        1e5        -       0.009

cin                 -        1e6        -       0.736
cin Faster          -        1e6        -       0.201
scanf               -        1e6        -       0.211
scanf Faster        -        1e6        -       0.209
fast reader         -        1e6        -       0.105
fast reader (fread) -        1e6        -       0.045

cin                 -        1e7        -       6.615
cin Faster          -        1e7        -       1.783
scanf               -        1e7        -       1.844
scanf Faster        -        1e7        -       1.826
fast reader         -        1e7        -       0.865
fast reader (fread) -        1e7        -       0.317

*/
