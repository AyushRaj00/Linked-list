#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    } 
};
//Passinga a  pointer by reference
void insertAtHead(node* &head,int d){

    if(head==NULL){
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next = head;
    head = n;

}


//Passinga a  pointer by value
void print(node*head){

    while(head!=NULL){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<endl;

}

int length(node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insertAtTail(node* &head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertAtMiddle(node* &head,int data,int p){
    //corner case
    if(head==NULL or p == 0){
        insertAtHead(head,data);
        return;
    }    
    else if(p>length(head)){
        insertAtTail(head,data);

    }
    else{
        //take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump++;        
        }
        //create a new node
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }

}

void deleteHead(node* &head){
    if(head == NULL){
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp; 
}

//Search Operation
//Linear Search

bool search(node*head,int key){
    node*temp = head;
    while(temp!=NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

/*
bool search(node*head, int key){
    node *temp = head;
    while(temp!=NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}
*/

//Recursively
bool searchRecursive(node*head, int key){
    if(head==NULL){
        return false;
    }
    //recurive case check at head, remaining linked list
    if(head->data == key){
        return true;
    }
    else{
        return searchRecursive(head->next, key);
    }
}

node* take_input(){

    int d;
    cin>>d;

    node*head = NULL;

    while(d!=-1){ 
        insertAtHead(head,d);
        cin>>d;

    }
    return head;

}

//OPERATOR OVERLOADING 

ostream& operator<<(ostream &os , node* head){
    print(head);
    return os;//cout
}

istream& operator>>(istream &is, node*head){
    head = take_input();
    return is;
}


void reverse(node* &head){
    node* C = head;
    node* P = NULL;
    node*N;

    while(C!=NULL){
        //save the next node 
        N=C->next;
        //make the current node point to prev 
        C->next = P;
        //update P & C then take 1 step forward
        P = C;
        C = N;
    }
    head = P;
}

//RECURSIVELY REVERSE A LINKED LIST

node* recReverse(node*head){
    //smallest linked list 
    if(head->next ==NULL or  head==NULL){
        return head;
    }

    //recurcive case
    node* shead = recReverse(head->next);

}



int main(){

    //node*head = take_input();
    //node*head2 = take_input();
    node*head;
    cin>>head;
    cout<<head;
    reverse(head);
    cout<<head;
    //node*head2;
    //cin>>head>>head2;
    //cout<<head<<head2;

    //print(head);
    /*
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    print(head);

    insertAtMiddle(head,4,3);
    print(head);
    insertAtTail(head,7);
    print(head);
    deleteHead(head);
    print(head);

    int key;
    cin>>key;

    if(searchRecursive(head, key)){
        cout<<"Key found";
    }
    else{
        cout<<"Key not found";
    }*/
    //return 0;
}