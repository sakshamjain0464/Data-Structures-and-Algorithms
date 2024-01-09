#include<iostream>
#include<conio.h>
using namespace std;

class Linked_list{
    struct node{
        int value;
        struct node *next;
    };
    struct node *start;
    int len;
    public:
    Linked_list(){
        start = NULL;
        len = 0;
    }

    void insertLast(int n){
        struct node *ptr = new struct node;
        ptr->next = NULL;
        ptr->value = n;
        if(start == NULL){
            start = ptr;
        }
        else{
            struct node *j = start;
            while(j->next != NULL){
                j = j->next;
            }
            j->next = ptr;
        }
        len++;
    }

    void insertBeg(int n){
        struct node *ptr = new struct node;
        if(start == NULL){
            ptr->next = NULL;
            ptr->value = n;
            start = ptr;
        }
        else{
            ptr->next = start;
            ptr->value = n;
            start = ptr;
        }
        len++;
    }

    void deleteBeg(){
        struct node *ptr;
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            ptr = start;
            start = start->next;
        }
        delete ptr;
        len--;
    }

    void deleteLast(){
        struct node *ptr, *previous;
        if(start == NULL){
            cout<<"Empty List";
        }
        else{
            struct node *j = start;
            while(j->next != NULL){
                    previous = j;
                    j = j->next;
                }
            previous->next = NULL;
            delete j;
            }
            len--;
        }

    void display(){
        struct node *j = start;
        if(start == NULL){
            cout<<"List Empty"<<endl;
        }
        int i = 0;
        while(j != NULL){
            cout<<"Element "<<i<<": "<<j->value<<endl;
            j = j->next;
            i++;
        }
        delete j;
    }
};


int main(){
    Linked_list l;
    int n;
    while(true){
        cout<<"OPTIONS:\n1.) Insert at Last\n2.) Insert at Beg\n3.) Insert at Specific Location\n4.)Delete from Beg\n5.) Delete from last\n6.) Delete from specific location\n7.) DIsplay\n8.) Exit"<<endl;
        cout<<"--> ";
        cin>>n;
        switch(n){
            case 1: {
                cout<<"Inserting at Last"<<endl;
                int value;
                cout<<"Enter Value to Insert";
                cin>>value;
                l.insertLast(value);
                break;
                }
            case 2: {
                cout<<"Inserting at beginning"<<endl;
                int value;
                cout<<"Enter Value to Insert";
                cin>>value;
                l.insertBeg(value);
                break;
                }
            case 3: cout<<3;break;
            case 4: {
                cout<<"Delete from beginning"<<endl;
                l.deleteBeg();
                break;
                }
            case 5: {
                cout<<"Delete from Last"<<endl;
                l.deleteLast();
                break;
                }
            case 6: cout<<6;break;
            case 7: {
                cout<<"Display Elements"<<endl;
                l.display();
                getch();
                break;
            }
            case 8: exit(0);
            default : "Invalid Value! Try Again";break;
        }
    }
    return 0;
}
