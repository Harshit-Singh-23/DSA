#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> a(n1);
    vector<int> b(n2);

    for(int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else if(b[j] < a[i]){
            arr[k] = b[j];
            j++;
            k++;
        }
        else if(a[i] == b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
    }
    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
    return arr;
}

vector<int> mergesort(vector<int> arr, int l, int r){
    
    if(l < r){
        int mid = (l + r) / 2;
        arr = mergesort(arr, l, mid);
        arr = mergesort(arr, mid + 1, r);
        arr = merge(arr, l, mid, r);
    } 
    return arr;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    arr = mergesort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}