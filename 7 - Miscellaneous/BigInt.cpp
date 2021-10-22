#include "bits/stdc++.h"
using namespace std;

#define pb push_back
namespace Big
{
    class Bigint
    {
    public:
        /// Constructor
        Bigint();
        Bigint(string);
        Bigint(long long);
        Bigint(const Bigint &);

        /// Alocation
        Bigint operator = (int);
        Bigint operator = (string);
        Bigint operator = (long long);

        int operator [] (int); /// Access

        /// Adding
        Bigint operator + (int);
        Bigint operator + (long long);
        Bigint operator + (const Bigint &);

        /// Subtraction
        Bigint operator - (int);
        Bigint operator - (long long);
        Bigint operator - (const Bigint &);

        /// Multiplication
        Bigint operator * (int);
        Bigint operator * (long long);
        Bigint operator * (const Bigint &);

        /// Compare
        bool operator <  (const Bigint &) const;
        bool operator <= (const Bigint &) const;
        bool operator >  (const Bigint &) const;
        bool operator >= (const Bigint &) const;
        bool operator == (const Bigint &) const;
        bool operator != (const Bigint &) const;

        /// Read & Write in Stream
        friend istream &operator >> (istream&, Bigint&);
        friend ostream &operator << (ostream&, Bigint&);

        /// Features
        void clear();
        Bigint abs();
        Bigint pow(int);
        string to_string();
        int digits() const;
        int trailingZeros() const;

    private:
        int base, pos;
        unsigned int skip;
        vector<int> number;
        static const int defaultBase = 1e9;

        int segmentLength(int) const;
        Bigint pow(int, map<int,Bigint>&);
    };

    Bigint::Bigint(){
        pos = 1; skip = 0;
        base = defaultBase;
    }

    Bigint::Bigint(string s):Bigint(){
        int sz = s.size();
        pos = (s[0] != '-');
        while(true){
            if(sz <= 0) break;
            if(!pos && sz<=1) break;

            int len=0, num=0, pre=1;
            for(int i=sz-1; i>=0 && i>=sz-9; i--,len++){
                if(s[i]<'0' || s[i]>'9') break;
                num += (s[i] - '0') * pre; pre *= 10;
            }
            number.pb(num); sz -= len;
        }
    }

    Bigint::Bigint(long long v):Bigint(){
        if(v < 0) pos = 0, v *= -1;
        while(v) number.pb(v%base), v/=base;
    }

    Bigint::Bigint(const Bigint &b):
        skip(b.skip), base(b.base),
        number(b.number), pos(b.pos){}

    Bigint Bigint::operator = (int v){return Bigint(v);}
    Bigint Bigint::operator = (string s){return Bigint(s);}
    Bigint Bigint::operator = (long long v){return Bigint(v);}

    Bigint Bigint::operator + (int v){return (*this)+(long long)v;}
    Bigint Bigint::operator + (long long v){
        Bigint ans = *this;
        auto it = ans.number.begin();
        if(skip > ans.number.size())
            number.insert(end(number), skip-number.size(), 0);

        it += skip;
        bool flag = true;
        while(v || flag){
            flag = false;
            if(it != end(number)){
                *it += (v%base); v/=base;
                v += (*it) / base;
                *it %= base; it++;
            } else{
                number.pb(0);
                it = end(number)-1;
            }
        }

        return ans;
    }

    Bigint Bigint::operator + (const Bigint &b){
        if(!b.pos) return (*this) - b;

        Bigint a = *this;
        auto &va = a.number;
        auto &vb = b.number;

        auto it = va.begin();
        auto jt = vb.begin();

        int sum = 0;
        while(it!=end(va) || jt!=end(vb)){
            if(it!=end(va)) sum += *it;
            else{va.pb(0); it=end(va)-1;}

            if(jt!=end(vb)) sum += *jt, jt++;
            *it = sum%base; sum/=base; it++; 
        }
        if(sum) va.pb(1);
        return a;
    }

    Bigint abs(Bigint);
    Bigint factorial(int);
    string to_string(Bigint&);
    Bigint factorail(long long);
}

int main(int argc, const char** argv) {

    return 0;
}