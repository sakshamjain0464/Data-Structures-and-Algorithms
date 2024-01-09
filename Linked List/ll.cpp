#include<iostream>
using namespace std;

class List{
    // NODE
    struct node{
        int data;
        struct node *next;
    };
    
    public:
    node *start;
    node *last;
    int count;
    
    List(){
        start = NULL;
        last = NULL;
        count = 0;
    }
// NODE INSERTION
    void insertBeg(int data){
        node *new_node = new node;
        new_node->data = data;
        if(start == NULL){
            start = new_node;
            last = new_node;
            new_node->next = NULL;
            new_node = NULL;
        }
        else{
            new_node->next = start;
            start = new_node;
            new_node = NULL;
        }
        count++;
        delete new_node;
    }

    void insertPos(int pos, int data){
        if(pos > count+1){
            cout<<"Invalid Position"<<endl;
        }
        else{
            if(start == NULL || pos == 1){
                insertBeg(data);
            }
            else if (pos == count+1){
                insertEnd(data);
            }   
            else{
                node *ptr = new node;
                ptr->data = data;
                node *temp = start;
                int curr = 1;
                while(curr<pos-1){
                    temp = temp->next;
                    curr++;
                }
                ptr->next = temp->next;
                temp->next = ptr;
                count++;
            }
        }
    }

    void insertEnd(int data){
        node *ptr = new node;
        ptr->data = data;
        ptr->next = NULL;
        if(start == NULL){
            start = ptr;
            last = ptr;
            ptr = NULL;
        }
        else{
            last->next = ptr;
            last = ptr;
            ptr = NULL;
        }
        count++;
        delete ptr;
    }

    void insertSorted(int data){
        node *ptr = new node;
        ptr->data = data;
        if(start == NULL){
            start = ptr;
            start->next = NULL;
            count++;
        }
        else if(count == 1){
            if(ptr->data < start->data ){
                insertBeg(data);
            }
            else{
                insertEnd(data);
            }
        }
        else{
            node *prev = NULL;
            node *curr = start;
            while(curr != NULL && curr->data < data){
                prev = curr;
                curr = curr->next;
            }
            if(curr == start){
                insertBeg(data);
            }
            else{
            prev->next = ptr;
            ptr->next = curr;
            count++;
            }
        }
    }

// NODE DELETION

    void deleteBeg(){
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else if(count == 1){
            node *temp = start;
            delete temp;
            start = NULL;
            last = NULL;
            count--;
        }
        else{
            node *temp = start;
            start = start->next;
            temp->next = NULL;
            count--;
            delete temp;
        }
    }

    void deletePos(int pos){
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else{
            if(pos > count){
                cout<<"Invalid Position"<<endl;
            }
            else if(pos == 1){
                deleteBeg();
            }
            else if(pos == count){
                deleteEnd();
            }
            else{
                node *temp = start;
                int curr = 1;
                while(curr < pos-1){
                    temp = temp->next;
                    curr++;
                }
                node *ptr = temp->next;
                temp->next = ptr->next;
                ptr->next = NULL;
                count--;
                delete ptr;
            }
        }
    }

    void deleteEnd(){
        if(start == NULL){
            cout<<"Empty List"<<endl;
        }
        else if(count == 1){
            node *temp = start;
            delete temp;
            start = NULL;
            last = NULL;
            count--;
        }
        else{
            node *temp = start;
            while(temp->next != last){
                temp = temp->next;
            }
            last = temp;
            temp = last->next;
            last->next = NULL;
            count--;
            delete temp;
        }
    }
    void display(){
        if(start == NULL){
            cout<<"List is Empty";
        }
        else{
            node *temp = start;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<"No. of elements are "<<count<<endl;
            delete temp;
        }
    }

    void sum(){
        if(start == NULL){
            cout<<"List is Empty";
        }
        else{
            int sum = 0;
            node *temp = start;
            while(temp!=NULL){
                sum+=temp->data;
                temp = temp->next;
            }
            cout<<sum<<endl;
            delete temp;
        }
    }

    void max(){
        if(start == NULL){
            cout<<"List is Empty";
        }
        else{
            int max = start->data;
            node *temp = start->next;
            while(temp!=NULL){
                if(temp->data > max){
                    max = temp->data;
                }
                temp = temp->next;
            }
            cout<<max<<endl;
            delete temp;
        }
    }
    void min(){
        if(start == NULL){
            cout<<"List is Empty";
        }
        else{
            int min = start->data;
            node *temp = start->next;
            while(temp!=NULL){
                if(temp->data < min){
                    min = temp->data;
                }
                temp = temp->next;
            }
            cout<<min<<endl;
            delete temp;
        }
    }

    int search(int data){
        if(start == NULL){
            cout<<"List is Empty";
        }
        else{
            int curr = 1;
            node *temp = start;
            while(temp!=NULL){
                if(temp->data == data){
                    return curr;
                }
                temp = temp->next;
                curr++;
            }
            return -1;
        }
    }

    void checkSorted(){
        if(start == NULL){
            cout<<"List is Empty"<<endl;
        }
        else{
            node *temp = start;
            int prev = start->data;
            bool check = true;
            while(temp != NULL){
                if(temp->data < prev){
                    check = false;
                    break;
                }
                prev = temp->data;
                temp = temp->next;
            }
            if(check == true){
                cout<<"List is Sorted"<<endl;
            }
            else{
                cout<<"List is not sorted"<<endl;
            }
        }
    }

    void deleteDup(){
        if(start == NULL){
            cout<<"List is Empty"<<endl;
        }
        else if(count == 1){
            cout<<"Completed"<<endl;
        }
        else{
            node *curr = start;
            node *next = start->next;
            while(next != NULL){
                if(next->data == curr->data){
                    curr->next = next->next;
                    next->next = NULL;
                    delete next;
                    next = curr->next;
                    count--;
                }
                curr = next;
                next = next->next;
            }
            cout<<"Completed"<<endl;
        }
    }

    void reverse(){
        if(start == NULL){
            cout<<"List is Empty"<<endl;
        }
        else{
            node *curr = start;
            node *next = NULL;
            node *prev = NULL;
            start = last;
            last = curr;
            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }
    }
};

int main(){
    List l1;
    l1.insertBeg(20);
    l1.insertEnd(30);
    l1.insertEnd(40);
    l1.insertEnd(40);
    l1.insertEnd(50);
    l1.insertEnd(55);
    l1.insertEnd(55);
    l1.insertEnd(60);
    l1.insertEnd(70);
    l1.display();
    l1.deleteDup();
    l1.reverse();
    l1.display();
    return 0;
}