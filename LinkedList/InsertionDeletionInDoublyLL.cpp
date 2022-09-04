#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    //constructor
    Node(int d){
       this->data = d;
       this->prev=NULL;
       this->next=NULL;
    }
    ~Node(){
        int val = this->data;
        while(next != NULL){
            delete next;
            next = NULL;
        }
       cout<<"memory free for node with data are: "<<val<<endl;
    }
};

//traverse doublylinkedlist
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        //cout current object
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//Method to find lenegth of doublylinkedlist
int getLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//Method to insert at start/head/begining 
void insertAtHead(Node* &head,Node* &tail, int d){
    //if koi node ni ha toh
    if(head == NULL) {
        Node* temp=new Node(d);
        head=temp;
        tail = temp;
    }
    //create new node
    else{
    Node* temp = new Node(d);
    
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

//Method to insert at tail/end/lastnode
void insertAtTail(Node* &head,Node* &tail, int d){
    
    //if koi node ni ha to
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    
    else{
    //create a new Node
    Node* temp = new Node(d);
    
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}

//insert at certain position
void insertAtPosition(Node* &tail,Node* &head, int position,int d){
    //insert at start
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }
    
    Node* temp = head;
    int cnt=1;
    while(cnt<position){
        temp = temp->next;
        cnt++;
    }
    //inserting at last
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }
    
    //creating a node for d 
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
    
}

//Deletion(at any position)  in doublylinkedlist
void deleteNode(int position, Node* &head){
    
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    } 
    else{
        
        //dleting at middle or last node 
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr -> next;
        curr->next = NULL;
        
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
     Node* tail = node1;
     
  /*   In case of no node or empty linkedlist 
     Node* head = NULL;
     Node* tail = NULL;*/
     
    print(head);
    //cout<<getLength(head);
    insertAtHead(head,tail,13);
    print(head);
    
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
    insertAtHead(head,tail,7);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
    
    insertAtHead(head,tail,15);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;

    insertAtTail(head,tail,22);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
    
    
    insertAtPosition(tail, head,2, 12);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
    
    insertAtPosition(tail, head,6, 2);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
    
    deleteNode(7,head);
    print(head);
    cout<<"head :: " <<head->data<<endl;
    cout<<"tail :: "<<tail->data<<endl;
}

