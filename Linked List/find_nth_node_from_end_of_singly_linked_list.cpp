int getNthFromLast(Node *head, int n)
    {
        if(head == NULL || n<1){
            return -1;
        }
        else{
            // reverse the list
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;
            int count = 1;
            
            while(curr!= nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            
            // Counting from the end
            count = count-1;
            curr = prev;
            if(count < n){  //If the number of nodes are less than n
                return -1;
            }
            
            count = 1;
            while(count < n){
                curr = curr->next;
                count++;
            }
            
            return curr->data;
        }
    }