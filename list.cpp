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

node* tail(node* &head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

void traverselist(node* &head){
    node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
    }
}

void traversetill(node* &head, int index){
    node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp -> next;
    }
    
}

void addfirst(node* &head, int val){
    node* n = new node(val);
    n -> next = head;
    head = n;

}

void addlast(node* &head, int val){
   
   node* n = new node(val);

   if(head == NULL){
       head = n;
       return;
   }
   
    node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;
}

void addAt(node* &head, int index, int val){
    node* n = new node(val);
    node* temp = head;
    for(int i = 0; i < index-1; i++){
        temp = temp -> next;
    }
    n -> next = temp -> next;
    temp = n;
     
}

int sizeoflist(node* &head){
    int size = 0;
    if(head == NULL){
        return size;
    }
    else {
        node* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            size++;
        }
        return size;
    }
}

int getfirst(node* &head){
    if(head == NULL){
        return -1;
    }
    else{
        node* temp = head;
        return temp -> data;
    }
    
}

int getlast(node* &head){
    if(head == NULL){
        return -1;
    }
    else{
        node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        return temp -> data;
    }
}

int getAt(node* &head, int index){
    int size = sizeoflist(head);
    if(head == NULL){
        cout << "the list is empty";
        return -1;
    }
    else if(index < 0 || index > size){
        cout << "invalid index";
        return -1;
    }
    else{
        node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp -> next;
        }
        return temp -> data;
    }    

}

bool search(node* &head, int target){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == target){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

int targetposition(node* &head, int target){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp -> data == target){
            return count;
        }
        count++;
        temp = temp -> next;
    }
    return -1;
}

void deletehead(node* &head){
    node* temp = head;
    head = head -> next;
    delete temp;
}

void deletelast(node* &head){
    node* temp = head;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

void deletenode(node* &head, int target){
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        deletehead(head);
    }

    node* temp = head;
    while(temp -> next -> data != target){
        temp = temp -> next;
    }
    node* todelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete todelete;
}

node* getnode(node* &head, int index){
    node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp -> next;
        }
        return temp;
}

node* reversedata(node* &head){                       // reverse list by swapping data
    int size = sizeoflist(head);

    node* temp = head;
    int lo = 0;
    int hi = size - 1;
    while(lo < hi){
        node* left = getnode(head, lo);
        node* right = getnode(head, hi);

        int temp = left->data;
        left->data = right->data;
        right->data = temp;
        lo++;
        hi--;
    }
    return head;
}

node* reverse(node* &head){                        // reverse list by reversing pointers
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* curr = head;
    node* prev = NULL;
    node* forw;
    
    while(curr != NULL){
        forw = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = forw;

    }
    return prev;

}

int kthfromlast(node* &head, int k){                 // two pointers used s means slow, f means fast.
    node* s = head;                                  
    node* f = head;
    for(int i = 0; i < k; i++){                     // moved f to k places ahead of s... to create a gap of k bw f and s
        f = f -> next;
    }
    while(f != NULL){                               // by this.. when the loop ends, s will be at kth position from the end.
        s = s->next;
        f = f->next;
    }
    return s->data;
}

int midoflist(node* &head){                            // gives the value in the mid node
    node* slow = head;
    node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
    }
    return slow->data;
}

node* midnode(node* &head){                           // gives the mid node.
    node* slow = head;
    node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
    }
    return slow;
}


node* merge2sortedlists(node* &head1, node* &head2){
    node* one = head1;
    node* two = head2;

    node* res = NULL;
    node* three = res;

    while(one != NULL && two != NULL){
        if(one->data < two->data){
            addlast(res, one->data);
            one = one->next;
        }
        else{
            addlast(res, two->data);
            two = two->next;
        }
    }
    while(one != NULL){
        addlast(res, one->data);
        one = one->next;
    }
    while(two != NULL){
        addlast(res, two->data);
        two = two->next;
    }
    return res;
}

void removeduplicates(node* &head){
    node* res = NULL;
    int size = sizeoflist(head);
    while(size > 0){
        int val = getfirst(head);
        deletehead(head);
        size--;
        int tail = getlast(res);
        if(res == NULL || tail != val){
            addlast(res,val);
        }
    }
    head = res;
}

void oddevenlist(node* &head){                   // places all the odd numbers first and then all the even numbers.
    node* even = NULL;
    node* odd = NULL;
    int size = sizeoflist(head);
    while(size > 0){
        int val = getfirst(head);
        deletehead(head);
        size--;
        if(val % 2 == 0){
            addlast(even, val);
        }
        else{
            addlast(odd, val);
        }
    }
    node* temp = odd;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp -> next = even;    
    head = odd;
}

// void kreverse(node* &head, int k){
//     node* prev = NULL;

//     while(sizeoflist(head) > 0){
//         node* curr = NULL;
//         if(sizeoflist(head) >= k){
//             for(int i = 0; i < k; i++){
//                 int val = getfirst(head);
//                 deletehead(head);
//                 addfirst(curr, val);
//             }
//             else{
//                 int s = sizeoflist(head);
//                 for(int i = 0; i < s; i++){
//                     int val = getfirst(head);
//                     deletehead(head);
//                     addlast(curr, val);
//                 }
//             }
//         }
//         if(prev == NULL){
//                 prev = curr;
//             }
//             else{
//                 node* tail1 = tail(prev);
//                 node* tail2 = tail(curr);
//                 tail1->next = curr;
//                 tail1 = tail2;
//             }
//         head = prev;
//     }
// }

bool isPalindrome(node* &head){
    if(head == NULL || head -> next == NULL) return true;

    node* mid = midnode(head);
    node* nhead = mid->next;
    mid->next = NULL;

    nhead = reverse(nhead);
    node* c1 = head;
    node* c2 = nhead;

    bool res = true;
    while(c2 != NULL){
        if(c1->data != c2->data){
            res = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    nhead = reverse(nhead);
    mid->next = nhead;

    return res;
}

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

// addlast(head, 1);
// addlast(head, 2);
// addlast(head, 3);
// addlast(head, 4);
// addfirst(head, 5);    

for(int i = 0; i < 7; i++){
    cin >> n;
    addlast(head, n);
}
printlist(head);
// cout << search(head, 56);
// cout << endl << targetposition(head, 78);
// deletelast(head);
// deletenode(head, 45);
cout << endl;
// cout << endl << "size of list is : " << sizeoflist(head);
// cout << endl << "first element is : " << getfirst(head);
// cout << endl << "last element is : " << getlast(head);
// cout << endl << getAt(head, 7);h
// reverse(head);
// addAt(head, 4, 89);
// node* x = reversedata(head);
// printlist(x);

// cout << endl << kthfromlast(head, 4);
// int z =  midoflist(head);
// cout << z;
//  removeduplicates(head);
// oddevenlist(head);
// kreverse(head, 3);
cout << isPalindrome(head) << endl;

printlist(head);
    return 0;
}