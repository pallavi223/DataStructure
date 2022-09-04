#include <iostream>

using namespace std;

//Implementation of Circular Linkedlist in Singly Linkedlist

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
       this->data = d;
       this->next = NULL;
    }
    
    ~Node(){
        int value = this->data;
        while(next != NULL){
            delete next;
            next = NULL;
        }
         cout<<"memory free for node with data are: "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    
    //empty list 
    if(tail == NULL){
        //create a Node
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //non- empty list
        //assuming that element is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //once current ka data equal to input element
        //element found -> current is representing element vala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

//Traversing in Circular LL 
void print(Node* tail){
    Node* temp = tail;
    
    //empty list
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return ;
    }
    
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

//Deletion at Circular LL
void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

int main(){
    
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);
    
    insertNode(tail,3,5);
    print(tail);
    
    insertNode(tail,5,7);
    print(tail);
    
    insertNode(tail,7,9);
    print(tail);
    
    insertNode(tail,5,6);
    print(tail);
    
    
    insertNode(tail,9,10);
    print(tail);
    
    deleteNode(tail,3);
    print(tail);
    
    return 0;
}