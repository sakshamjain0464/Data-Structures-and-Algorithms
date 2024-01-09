#include<iostream>
using namespace std;

class Queuell{
    struct node{
        int data;
        struct node* next;
    };
    node* front;
    node* rear;
    public:
    Queuell(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data){
        node* ptr = new node;
        ptr->data = data;
        ptr->next = NULL;
        if(front == NULL){
            front = rear = ptr;
        }
        else{
            rear->next = ptr;
            rear = ptr;
        }
        cout<<"Enqueued "<<data<<endl;
    }

    void dequeue(){
        int data;
        if(front == NULL){
            cout<<"Queue Underflow"<<endl;
        }
        else if(front == rear){
            data = front->data;
            delete front;
            front = rear = NULL;
            cout<<"Dequeued "<<data<<endl;
        }
        else{
            data = front->data;
            node* temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            cout<<"Dequeued "<<data<<endl;
        }
    }

    void display(){
        if(front == NULL){
            cout<<"Queue Underflow"<<endl;
        }
        else{
        node* temp = front;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        }
    }
};

int main(){
    Queuell q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    return 0;
}
