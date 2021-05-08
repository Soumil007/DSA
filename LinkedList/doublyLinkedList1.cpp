#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};
void insertAtBegin(Node **head,int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;  
    if(head!=NULL){
        new_node->next = *head;
        new_node->prev = *head;
        *head = new_node;
    }else{
        new_node->next = NULL;
        new_node->prev = *head;
        *head = new_node;
    }
}
void insertAtEnd(Node **head, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    Node *ptr = *head;
    if(head!=NULL){
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        new_node->prev = ptr;
        ptr->next = new_node;
        new_node->next = NULL;
    }else{
        insertAtBegin(head,new_data);
    }
}
void insertAtPos(Node **head,int new_data,int pos){
    Node *new_node = new Node();
    new_node->data = new_data;
    Node *ptr = *head;
    // Node *temp = NULL;
    if(head!=NULL){
        int i =0;
        while(i<(pos-2) && ptr){
            ptr=ptr->next;
            i++;
        }
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        new_node->prev = ptr;
        ptr->next = new_node;
    }else{
        cout<<"Head is NULL"<<endl;
        return;
    }
}
void printList(Node **head){
    Node *ptr = *head;
    if(head!=NULL){
        // while(ptr->next!=NULL){
        //     cout<<ptr->data<<" ";
        // }
        do{
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }while(ptr!=NULL);

        cout<<endl;
    }
}

int main(){
    Node* head = NULL;
    insertAtBegin(&head,10);
    insertAtBegin(&head,20);
    insertAtBegin(&head,30);
    insertAtEnd(&head,50);
    insertAtEnd(&head,100);
    insertAtEnd(&head,500);
    insertAtPos(&head,-1,2);
    insertAtPos(&head,-99,4);
    printList(&head);
    return 0;

}