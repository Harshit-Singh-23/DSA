#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void duplicatebrackets(string str)               // checks whether a string has duplicate brackets.. (extra brackets)
{                                                //   ((a+b) + (c+d))    will give false ... bcoz no extra bracket
    stack<char> st;                              //   (a+b) + ((c+d))    will give true .. bcoz there are extra brackets.
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);
        if (ch == ')'){
            if(st.top() == '('){
                cout << endl << "true";
                return;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
        else{
            st.push(ch);
        }
    }
    cout << endl << "false";
}

void balancedbrackets(string str) {                          // checks whether brackets are balanced, means opened and closed properly.
  stack<char> st;
  for (int i = 0; i < str.length(); i++) {
    char ch = str.at(i);
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    }
    else if(ch == ')'){
      if(st.empty()){
        cout << "false";
        return;
      }
      else if(st.top() != '('){
        cout << "false";
        return;
      }
      else{
        st.pop();
      }
    }
    else if(ch == '}'){
     if(st.empty()){
        cout << "false";
        return;
      }
      else if(st.top() != '{'){
        cout << "false";
        return;
      }
      else{
        st.pop();
      }  
    }
    else if(ch == ']'){
     if(st.empty()){
        cout << "false";
        return;
      }
      else if(st.top() != '['){
        cout << "false";
        return;
      }
      else{
        st.pop();
      }
    }
    else{

    }
  }
  if (st.empty()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }

}

vector<int> nextgreaterelement(vector<int> arr){      // return arr with elements replaced with the next greater element on the right side.
  vector<int> nge(arr.size());                        // eg ->   [2,5,3,6,7,8,6,7]  returns  [5,6,6,7,8,-1,7,-1].
  stack<int> st;                                      // -1 is if no element is greater on right side.
  int n = arr.size();
  st.push(arr[n-1]);
  nge[n-1] = -1;

  for(int i = arr.size()-1; i >= 0; i--){
    // pop till greater element found --> answer --> push current element

    while(st.size() > 0 && arr[i] >= st.top()){
      st.pop();
    }

    if(st.size() == 0){
      nge[i] = -1;   
    }
    else{
      nge[i] = st.top();
    }
    st.push(arr[i]);
  }
  return nge;
}

vector<int> stock_span(vector<int> arr){
  vector<int> span(arr.size());
  stack<int> st;
  st.push(0);
  span[0] = 1;

  for(int i = 1; i < arr.size(); i++){
    while(st.size() > 0 && arr[i] > st.top()){
      st.pop();
    }
    if(st.size() > 0){
      span[i] = i + 1;
    }
    else{
      span[i] = i - st.top();
    }
    st.push(i);
  }
  return span;
}

int max_area_histogram(vector<int> arr){
  vector<int> rb(arr.size());                     // right boundary
  vector<int> lb(arr.size());                      // left boundary

  stack<int> st;
  st.push(arr.size()-1);
  rb[arr.size()-1] = arr.size();              // since any smaller element wont be on the right side of the last element,
//                                               so its right boundary will be the size of array. 

  for(int i = arr.size()-2; i >= 0; i--){
    while(st.size() > 0 && arr[i] <= arr[st.top()]){
      st.pop();
    }

    if(st.size() == 0){
      rb[i] = arr.size();            // for any element whose smaller element cant be found on right side, gets default value as arr.size().
    }
    else{
      rb[i] = st.top();
    }
    st.push(i);
  }

//   stack<int> st2;
  st.push(0);
  lb[0] = -1;              // since any smaller element wont be on the left side of the first element,
//                                                   so its left boundary will be -1. 

  for(int i = 1; i < arr.size(); i++){
    while(st.size() > 0 && arr[i] <= arr[st.top()]){
      st.pop();
    }

    if(st.size() == 0){
      lb[i] = -1;            // for any element whose smaller element cant be found on left side, gets default value as -1.
    }
    else{
      lb[i] = st.top();
    }
    st.push(i);
  }

  int maxarea = 0;
  for(int i = 0; i < arr.size(); i++){
    int width = rb[i] - lb[i] - 1;
    int area = width * arr[i];
    if(area > maxarea){
      maxarea = area;
    }
  }
  return maxarea;
}

  int maxarea = 0;
  for(int i = 0; i < arr.size()-1; i++){
    int width = rb[i] - lb[i] - 1;
    int area = width * arr[i];
    if(area > maxarea){
      maxarea = area;
    }
  }
  return maxarea;
}


int main()
{
    // string str;
    // getline(cin, str);
    // duplicatebrackets(str);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << max_area_histogram(arr);

    return 0;
}


