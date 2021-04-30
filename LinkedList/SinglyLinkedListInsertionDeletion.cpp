#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Definition of node
class Node{
    public:
        int data;
        Node* next;
};
//function to insert at begining
void insertAtBegin(Node **head,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}
//function to insert at the end
void insertAtEnd(Node **head,int new_data){
    Node* new_node = new Node();
    if(new_node){
        cout<<endl<<"Node Created";
    }
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head == NULL){
        cout<<endl<<"Head NULL";
        *head = new_node;
        return; 
    }else{
        Node *ptr = *head;
        cout<<endl<<"Adding";
        while(ptr->next!=NULL){
            ptr=ptr->next;
            
        }
        ptr->next = new_node;
    }

}
//function to insert in between two nodes
void insertAfterGivenNode(Node **head,int position,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    int i = 0;
    Node* ptr = *head;
    while(i!=position-1){
        ptr=ptr->next;
        i++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;

}
//function to delete a node from linkedList With a given value
void deleteNodeWithValue(Node **head,int value){
    cout<<"deleting"<<endl;
    Node *prev=NULL,*temp = *head;
    if(temp == NULL){
        cout<<"Linked List empty!!"<<endl;
        return;
    }else{
        if(temp->data == value){
            *head = temp->next;
            delete temp;
        }else{
            while(temp->data!=value && temp->next!=NULL){
               prev = temp;
               temp = temp->next; 
            }
            if(temp!=NULL){
                prev->next = temp->next;
                delete temp;
            }
        }
    }
}
//function to delete a node at a position
void deleteNodeGivenPosition(Node **head,int position){
    Node *prev=NULL,*temp=*head;
    int i=0;
    // if(temp!=NULL){
    //     cout<<"deleting"<<endl;
    //     while(i<position-1 && temp->next!=NULL){
    //         prev = temp;
    //         temp = temp->next;
    //         i++;
    //     }
    //     if(temp!=NULL){
    //         prev->next = temp->next;
    //         delete temp;
    //     }
        
    // }else{
    //     cout<<"Linked List Empty"<<endl;
    //     return;
    // }
    if(temp == NULL){
        cout<<"Linked List Empty"<<endl;
        return;
    }else{
        if(position == 1){
            *head = temp->next;
            delete temp;
        }else{
            i=0;
            while(i<position-1 && temp->next!=NULL){
                prev = temp;
                temp = temp->next;
                i++;
            }
            if(temp!=NULL){
                prev->next = temp->next;
                delete temp;
            }
        }
    }
}
//function to print the list
void printList(Node *node){
    cout<<endl<<"printing List"<<endl;
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}
//driver program
int main(){
    Node *head = NULL;
    insertAtBegin(&head,6);
    insertAtBegin(&head,7);
    insertAtEnd(&head,10);
    insertAfterGivenNode(&head,2,5);
    insertAfterGivenNode(&head,1,20);
    printList(head);
    // deleteNodeWithValue(&head,10);
    // printList(head);
    // deleteNodeWithValue(&head,7);
    // printList(head);
    // deleteNodeWithValue(&head,6);
    // printList(head);
    // deleteNodeGivenPosition(&head,1);
    // printList(head);
    // deleteNodeGivenPosition(&head,4);
    // printList(head);
    return 0;
}




