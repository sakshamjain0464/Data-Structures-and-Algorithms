#include<iostream>
using namespace std;

class doublyLL{
    struct node{
        node *prev;
        int data;
        node *next;
    };
    public:
    node *start;
    node *last;
    int count;
    doublyLL(){
        start = NULL;
        last = NULL;
        count = 0;
    }

    // Insertion
    void insertBeg(int data){
        node *ptr = new node;
        ptr->data = data;
        if(start == NULL){
            start = ptr;
            last = ptr;
            start->next = NULL;
            start->prev = NULL;
            count++;
        }
        else{
            start->prev = ptr;
            ptr->next = start;
            ptr->prev = NULL;
            start = ptr;
            count++;
        }
    }

    void insertEnd(int data){
        if(start == NULL){
            insertBeg(data);
        }
        else{
            node *ptr = new node;
            ptr->data = data;
            ptr->next= NULL;
            last->next = ptr;
            ptr->prev = last;
            last = ptr; 
            count++;
        }
    }

    void insertPos(int pos, int data){
        if(start == NULL || pos == 1){
            insertBeg(data);
        }
        else if(count == 1 || pos == count+1){
            insertEnd(data);
        }
        else if(pos < 1 || pos > count+1){
            cout<<"Invalid Position"<<endl;
        }
        else{
            node  *ptr = new node;
            ptr->data = data;
            node *temp = start;
            int curr = 1;
            while(curr < pos){
                temp = temp->next;
                curr++;
            } 
            ptr->next = temp;
            ptr->prev = temp->prev;
            ptr->prev->next = ptr;
            temp->prev = ptr;
            count++;
        }
        cout<<"Element inserted at Position "<<pos<<endl;
    }

    // DELETION
    void deleteBeg(){
        int data;
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else if(count == 1){
            data = start->data;
            delete start;
            start = NULL;
            last = NULL;
            count--;
        }
        else{
            data = start->data;
            node *temp = start;
            start = start->next;
            start->prev = NULL;
            delete temp;
            count--;
        }
        cout<<"Deleted "<<data<<endl;
    }

    void deleteEnd(){
        int data;
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else if(count == 1){
            data = last->data;
            delete last;
            start = NULL;
            last = NULL;
            count--;
        }
        else{
            data = last->data;
            node *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
            count--;
        }
        cout<<"Deleted "<<data<<endl;
    }

    void deletePos(int pos){
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else if(count == 1 || pos == 1){
            deleteBeg();
        }
        else if(pos == count){
            deleteEnd();
        }
        else if(pos > count){
            cout<<"Invalid position"<<endl;
        }
        else{
            int data;
            node *temp = start;
            int curr = 1;
            while(curr<pos){
                temp = temp->next;
                curr++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            data = temp->data;
            delete temp;
            cout<<"Deleted "<<data<<endl;
            count--;
        }
    }
    // Display
    void display(){
        node *temp = start;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<"Number of Elements are : "<<count<<endl;
    }

    // Print Reverse
    void printRev(){
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            node *temp = last;
            while(temp != NULL){
                cout<<temp->data<<endl;;
                temp = temp->prev;
            }
        }
    }

    void reverse(){
        if(start==NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            node* prev = NULL;
            node* curr = start;
            node* next = NULL;
            start = last;
            last = curr;
            while(curr!=NULL){
                next = curr->next;
                curr->next = prev;
                curr->prev = next;
                prev = curr;
                curr = next;
            }
        }
    }
};


int main(){
    doublyLL l1;
    l1.insertBeg(5);
    l1.insertBeg(4);
    l1.insertBeg(3);
    l1.insertBeg(2);
    l1.insertBeg(1);
    l1.insertEnd(2);
    l1.insertPos(3, 8);
    l1.display();
    l1.reverse();
    l1.display();
    return 0;
}