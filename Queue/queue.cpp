#include<iostream>
using namespace std;

class Queue{
    int *s;
    int size;
    int front;
    int rear;

    public:
    Queue(int size){
        this->size = size;
        s = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    void enqueue(int data){
       if(rear == size-1){
        cout<<"Queue Overflow"<<endl;
       }
       else{
            if(front == -1){
                s[++front] = data;
                rear++;
            }
            else{
                s[++rear] = data;
            }
            cout<<"Enqueued "<<data<<endl;
       }
    }

    void dequeue(){
        if(rear == -1){
            cout<<"Queue Underflow"<<endl;
        }
        else if(front == rear){
            cout<<"Dequeued "<<s[front]<<endl;
            rear = front = -1;
        }
        else{
            cout<<"Dequeued "<<s[front++]<<endl;
        }
    }

    void display(){
        if(rear == -1){
            cout<<"Queue Underflow"<<endl;
        }
        else{
            for(int i = front; i<=rear; i++){
                cout<<s[i]<<endl;
            }
        }
    }
};

int main(){
    Queue q1(5);
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