#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;    
};

void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main(){
    Node *n1,*n2,*n3;
    n1 = new Node();
    n2 = new Node();
    n3 = new Node();
    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = NULL;

    cout<<"printing\n";
    printList(n1);
    cout<<endl;

    return 0;
}