#include <iostream>

using namespace std;

//Implementation of node  which has data and store add of next pointing node

class Node{
    public:
    int data;
    Node* next;  // pointer of Node type
    
    //define constructor to initialize value of data
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


    //Create a destructor to delete memory manually 
    ~Node(){
       int value =  this->data;
       
       //code to free memory
       if(this->next != NULL){
           delete next;
           this->next = NULL;
       }
       cout<<"Memory is free for value: "<<value<<endl;
    }

};
    
    //Insert at start/begining/head  in Singly LinkedList
    
    void insertAtHead(Node* &head,int d){
        //create new Node
        Node* temp = new Node(d);
        temp -> next = head;
        
        //update head 
        head = temp;
        
    }

    //Insert at end/tail/last  in Singly LinkedList
    void insertAtTail(Node* &tail,int d){
        //create new Node
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = tail -> next;  // we can also write this way (tail = temp)
        
    }


    //Insert at certain position (insert at 3rd pos) or Middle  in Singly LinkedList
     void insertPosition(Node* &tail, Node* &head, int position, int d){
        
        //insert at start(pos = 1) position
        if(position == 1){
            insertAtHead(head,d);
            return;
        }
        Node* temp = head;
        int cnt = 1;
        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        }
            //insert at end or last position
         if(temp -> next == NULL) {
           insertAtTail(tail,d);
           return;
        }
        Node* nodeToInsert = new Node(d);
        nodeToInsert -> next = temp -> next;
        temp-> next = nodeToInsert;
        
    }
    
      //Delletion at LL at certain position
     void deleteAtPosition(int position, Node* &head){
        //delete at start(first node)
        
        if(position == 1){
            Node* temp = head;
            head = head->next;
            //memory free for starting Node
            temp -> next = NULL;
            delete temp;
        } 
        else{
            //delete middle node or last node
            Node* curr = head;
            Node* prev = NULL;
            int cnt=1;
            while(cnt < position){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
        
    }
    //Method to traverse or print a LinkedList
    void print(Node* &head){
        Node *temp = head;
        while(temp != NULL){
            //print current Node data
            cout<< temp -> data<<" ";
            //increment temp to point next Node
            temp = temp -> next;
        }
        cout<<endl;
    }


int main()
{
    Node* node1 = new Node(10);
    /*cout<< node1 -> data<<endl;
    cout<< node1 -> next;*/
    
    //head pointed to node1
    Node* head = node1;
    //tail pointed to next node
    Node* tail = node1;
    
    
    print(head);
    // insertAtHead(head, 12);
    
   insertAtTail(tail,12);
   
    //print(head);
   // insertAtHead(head, 15);

    insertAtTail(tail,15);
     print(head);
    insertPosition(tail,head,3,22);
    print(head);
   
    cout<<"head :: "<<head->data<<endl;  
    cout<<"tail :: "<<tail->data<<endl;

    deleteAtPosition(4,head);
    print(head);
}


/** output:
10 
10 12 15 
10 12 15 22 
head :: 10
tail :: 22
Memory is free for value: 15
10 12 70 
**/
