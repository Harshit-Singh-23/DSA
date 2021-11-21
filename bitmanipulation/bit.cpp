#include <iostream>
#include <bits/stdc++.h>

using namespace std;                // right shift -->  x = x * 2^n;         for x << n;
//                                     left shift --> x = x / 2^n;         for x >> n;






int main(){

    int x = 8;                     
    int y = x << 2;                // << is right shift. it moves all the bits of the number to right side by the number given. in this case 2.
    int z = x >> 2;                // >> is left shift. it moves all the bits of the number to left side by the number given. in this case 2.

    cout << x << " " << y << " " << z;

    return 0;
}