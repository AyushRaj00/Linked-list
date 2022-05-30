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

void reverse(node* &head){
    node*c = head;
    node*p = NULL;
    node*n;

    while (c!= NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
}

int main(){
    node*head = NULL;
    //cin>> head;
    cout << head;
}
