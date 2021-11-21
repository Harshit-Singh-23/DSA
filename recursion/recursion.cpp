#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sumtilln(int n){

    if(n == 0){
        return 0;
    }

    int prevsum = sumtilln(n-1);
    return n + prevsum;
}

long long int factorial(int n)
{
    long long int recAns = 1;
    if (n > 0)
        recAns = n * factorial(n - 1);

    return recAns;
}

int npowerp(int n, int p){
    int ans = 0;

    if(p == 0){
        return 1;
    }

    ans = n * npowerp(n, p-1);
    return ans;
}

// void fibonaccitilln(int n){

//     if(n == 1){
//         cout << 1;
//     }
//     int c;
//     fibonaccitilln(n-1) + fibonaccitilln(n-2);
    
// }

int main(){

    int x;
    int p;
    cin >> x >> p;


    // cout << sumtilln(x);
    // cout << factorial(x);
    cout << npowerp(x, p);

    return 0;
}