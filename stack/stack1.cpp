#include <iostream>                                    // stack class implementation using array

using namespace std;

# define n 100

class stack {
    int* arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int val){
        if(top == n-1){
            cout << "stack overflow." << endl;
            return;
        }
        top++;
        arr[top] = val;
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
};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Top is : " << st.Top();
    st.pop();
    st.pop();
    st.pop();
    cout << endl << "Top is : " << st.Top();
    cout << endl << st.empty();
    st.pop();
    st.pop();
    cout << endl << "Top is : " << st.Top();
    cout << endl << st.empty();



    return 0;
}