#include <bits/stdc++.h>                                    // stack class implementation using array

using namespace std;

# define n 100

class stack1 {
    int* arr;
    int top;
    int min;

    public:
    stack1(){
        arr = new int[n];
        top = -1;
        min = INT_MAX;
    }

    void push(int val){
        if(top == n-1){
            cout << "stack overflow." << endl;
            return;
        }
        top++;
        arr[top] = val;
        if(val < min){
            min = val;
        }
    }

    void pop(){
        if(top == -1){
            cout << "No element to pop." << endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
            cout << endl << "No element in stack.";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        else return false;
    }

    int getmin(){
        return min;
    }
};

int main(){

    stack1 st;
    st.push(10);
    st.push(2);
    st.push(30);
    st.push(1);
    st.push(5);
    cout << "Top is : " << st.Top();
    st.pop();
    st.pop();
    st.pop();
    cout << endl << "Top is : " << st.Top();
    cout << endl << st.empty();

    cout << endl << "Top is : " << st.Top();
    cout << endl << st.empty();
int m= st.getmin();
    cout << endl << m;



    return 0;
}