#include "1.h"
List::List(){
	head = NULL;
}

List::~List(){
	Node* walker = head;
    while(walker!=NULL){
        head=walker;
        walker=walker->next;
        delete head;
    }
    walker=NULL;
    head=NULL;
}

bool List::isEmpty(){
	return (head == NULL);
}

void List::append(Item* value){
    Node* walker=head;
    Node* n=new Node;
    n->data=value;
    if (head==NULL) {
        head=n;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        while (walker->next!=NULL) {
            walker=walker->next;
        }
        walker->next=n;
        n->prev=walker;
        n->next=NULL;
    }
}

int List::find(Item* value){
	int count=0;
    Node* walker=head;
    if (head==NULL) {
        return 0;
    }
    while (walker!=NULL) {
        count++;
        if (walker->data==value) {
            break;
        }
        if (walker->next==NULL) {
            return 0;
        }
        walker=walker->next;
    }
    return count;
}

int List::getSize(){
	if (head==NULL) {
        return 0;
    }
    int count=0;
    Node* walker=head;
    while (walker!=NULL) {
        count++;
        walker=walker->next;
    }
    return count;
}

void List::removeNth(int n){
    int number=0;
    Node* walker=head;
    Node* trailer;
    while (number<n-1) {
        number++;
        trailer=walker;
        walker=walker->next;
    }
    if (this -> getSize()==1 && n==1) {
        //delete l.head;
        head=NULL;
    }
    else if (n==1) {
        Node* del=head;
        head=head->next;
        head->prev=NULL;
        del=del;	//no-op to remove unused but set variable compile warning
        del=NULL;
    }
    else{
        if (walker->next==NULL) {
            trailer->next=NULL;
            //delete walker;
            walker=NULL;
        }
        else{
           trailer->next=walker->next;
           walker->next->prev=walker->prev;
           //delete walker;
           walker=NULL;
        }
    }
}
