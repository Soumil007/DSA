#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
//function to insert at the begining
void insertAtBegin(Node **head,int new_data){
    
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    Node *ptr  = *head;
    if(*head!=NULL){
        while(ptr->next!=*head){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }else{
        new_node->next = new_node;
    }
    *head = new_node;

}
//function to insert at end
void insertAtEnd(Node **head,int new_data){
    Node *temp = *head;
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head == NULL){
        insertAtBegin(head,new_data);
        return;
    }else{
        while(temp->next!=*head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}
//function to delete the first node
void deleteBegin(Node **head){
    
    Node *ptr = *head;
    Node *temp  = *head;
    if(head!=NULL){
        while(ptr->next!=*head){
            ptr=ptr->next;
            
        }
        ptr->next = temp->next;
        delete temp;
        *head = ptr->next;


    }else{
        cout<<"Circular List empty!!";
        return;
    }
}

//delete a node at a given position
void deleteWithGivenPosition(Node **head,int pos){
    Node *ptr= *head,*temp = *head;
    if(head!=NULL){
        int i=0;
        while(ptr->next && i<pos-1){
            temp = ptr;
            ptr=ptr->next;
            i++;
        }
        temp->next = ptr->next;
        delete ptr;
    }else{
        cout<<"Circular List Empty"<<endl;
    }
}

//function to print the Linked List
void printList(Node *head){
    cout<<"Printing List"<<endl;
    Node *ptr = head;
    if(head!=NULL){
        do{
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }while(ptr!=head);
        cout<<endl;
    }else{
        cout<<"LinkedList empty!";
    }
    
}
int main(){
    Node *head = NULL;
    
    insertAtEnd(&head,7);
    insertAtBegin(&head,1);
    insertAtEnd(&head,6);
    insertAtBegin(&head,2);
    insertAtBegin(&head,3);
    
    printList(head);

    deleteBegin(&head);
    printList(head);

    deleteWithGivenPosition(&head,2);
    printList(head);
    return 0;
}