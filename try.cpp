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

int main(){

    int arr[3] = {100,180,200};

    int x = trial(arr,3);

    cout << x;


    

    return 0;
}