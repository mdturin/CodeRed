#include "bits/stdc++.h"
using namespace std;

int main(int argc, const char** argv) {

    bitset< 20 > bs;  cout << bs << "\n"; 

    bs[0] = 1;  cout << bs << "\n";
    bs[19] = 1; cout << bs << "\n";

    cout << bs.size()  << '\n';
    cout << bs.count() << '\n';

    cout << bs.test(3) << '\n';
    cout << bs.test(0) << '\n';

    /**
        bitset< const size > NAME;

        bs.all();           // true, if all bit is set
        bs.any();           // true, if any bit is set
        bs.none();          // true, if no bit is set

        bs.size();          // return size
        bs.count();         // return number of set bit

        bs.test(pos);       // return 1, if set

        bs.set();           // set all
        bs.set(pos);        // set in pos
        bs.set(pos, value); // set in pos with value
        
        bs.flip();          // flip all;
        bs.flip(pos);       // flip in pos

        bs.reset();         // reset all to 0
        bs.reset(pos);      // reset pos to 0

        opeators can be used :
            ==, !=
            &, |, ^, ~
            &=, |=, ^=
            <<, <<=, >>, >>=

        and also [] operator can be used
    */

    return 0;
}