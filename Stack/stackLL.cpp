#include<iostream>
using namespace std;

class Stack{
    struct node{
        int data;
        node* next;
    };
    node* top;

    public:
    Stack(){
        top = NULL;
    }

    void push(int data){
        node* ptr = new node;
        ptr->data = data;
        if(isEmpty()){
            top = ptr;
            ptr->next = NULL;
        }
        else{
            ptr->next = top;
            top = ptr;
        }
        cout<<"Pushed "<<data<<endl;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            int data = top->data;
            node *temp = top;
            top = top->next;
            delete temp;
            cout<<"Popped "<<data<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"TOP : "<<top->data<<endl;
        }
    }

    bool isEmpty(){
       if(top == NULL){ 
            return 1; 
        }
        else{
            return 0;
        }
    }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(2);
    s1.push(4);
    s1.push(5);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.pop();
    return 0;
}
