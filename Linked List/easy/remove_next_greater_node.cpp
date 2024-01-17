Node *compute(Node *head)
    {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        curr = head;
        Node* max = head;
        Node* temp;
        
        while(curr != nullptr && curr->next != nullptr){
            if(curr->next->data < max->data){
                temp = curr->next;
                curr->next = temp->next;
            }
            else{
                curr = curr->next;
                max = curr;
            }
        }
        
        curr = head;
        prev = nullptr;
        next = nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }