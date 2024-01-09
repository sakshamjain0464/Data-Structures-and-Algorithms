#include<iostream>
using namespace std;

class Stack{
    int *s;
    int size;
    int top;

    public:
    Stack(int size){
        this->size = size;
        s = new int[size];
        top = -1;
    }

    void push(int data){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            s[++top] = data;
            cout<<"Pushed "<<data<<endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"Popped "<<s[top--]<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            cout<<"TOP : "<<s[top]<<endl;
        }
    }

    bool isFull(){
       if(top == size-1){ 
            return 1; 
        }
        else{
            return 0;
        }
    }

    bool isEmpty(){
       if(top == -1){ 
            return 1; 
        }
        else{
            return 0;
        }
    }
};

int main(){
    Stack s1(5);
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