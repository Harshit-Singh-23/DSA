#include <iostream>
#include <set>
#include <bits/stdc++.h>

using namespace std;

vector<int> removeduplicates(vector<int> arr){
    set<int> s;
    for(auto x : arr){
        s.insert(x);
    }
    arr.resize(0);
    for(auto x : s){
        arr.push_back(x);
    }
    return arr;
}

int main()
{

    set<int> s;
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    arr = removeduplicates(arr);
    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}