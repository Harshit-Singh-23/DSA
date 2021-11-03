#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL; 
    }
};

void printlist(node* n){
    node* temp = n;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main(){
int n;
node* head = NULL;
    
    
    
    return 0;
}