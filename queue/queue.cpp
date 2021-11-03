#include <iostream>

using namespace std;

# define n 100

class queue {
    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val){
        if(back == n-1){
            cout << "queue overflow." << endl;
            return;
        }
        back++;
        arr[back] = val;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front > back){
            cout << "No elements in queue." << endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout << endl << "No elements in queue ";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        else return false;
    }

    int size(){
        int count = 0;
        if(front == -1 || front > back){
            return -1;
        }
        for(int i = front; i < back; i++){
            count++;
        }
        return count+1;
    }
};

int main(){

    queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "size of queue is : " << q.size();
    cout << endl << q.peek();
    q.pop();
    q.pop();
    cout << endl << "size of queue is : " << q.size();
    q.pop();
    cout << endl << "size of queue is : " << q.size();
    cout << endl << q.empty();

    cout << endl << q.peek();
    q.pop();
    q.pop();
    cout << endl << q.empty();



    return 0;
}