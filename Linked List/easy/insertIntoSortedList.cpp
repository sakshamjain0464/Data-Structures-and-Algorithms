Node* reverseDLL(Node * head)
    {
        if(head == nullptr || head->next == nullptr){ //If list has only one element
            return head;
        }
        else{
            Node* prev = nullptr;  //Initialize the pointers
            Node* curr = head;
            Node* next = nullptr;
            
            // Swapping the links
            while(curr != nullptr){
                next = curr->next;
                curr->next = prev;
                curr->prev = next;
                prev = curr;
                curr = next;
            }
            
            return prev;  //Return head
        }
    }