#include <bits/stdc++.h>

using namespace std;

// ######### kadane's algo ############

int maxsubarraysum(vector<int> arr){           // max sum of a subarray using KADANE'S algo
    int currentsum = 0;
    int maxsum = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        currentsum += arr[i];
        if(currentsum < 0) currentsum = 0;
        maxsum = max(maxsum, currentsum);
    }
    return maxsum;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxsubarraysum(arr);

    return 0;
}