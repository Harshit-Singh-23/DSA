#include <bits/stdc++.h>

using namespace std;

int trial(int arr[], int len){
    int count = 0;
    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if((arr[j] - arr[i]) > 0) count++;
        }
    }

    return count;

}


int jump(int A[], int n) {
	 if(n<2)return 0;
	 int level=0,currentMax=0,i=0,nextMax=0;

	 while(currentMax-i+1>0){		
		 level++;
		 for(;i<=currentMax;i++){	
			nextMax=max(nextMax,A[i]+i);
			if(nextMax>=n-1)return level; 
		 }
		 currentMax=nextMax;
	 }
	 return 0;
}

void countRecurringDigits(long long int a){    // prints how many times a digit occurs in a number.
    vector<int> arr(10,0);
    while(a > 0){
        
        int x = a % 10;
        arr[x]++;
        
        a = a / 10;
    }
    
    for(int i = 0; i < arr.size(); i++){
        cout << i << " -> " << arr[i] << " times." << endl;
    }
}

void printMessage(){                // takes input string from user until user types "xdone" and then prints the text.
    string str = "";
    string s;
    while(s != "xdone"){
        s = "";
        getline(cin, s);
        if(s == "xdone") break;
        
        str += "\n";
        str += s;
    }
    cout << str;
}

int main(){

    int arr[3] = {100,180,200};

    int x = trial(arr,3);

    cout << x;

// hi there
    

    return 0;
}