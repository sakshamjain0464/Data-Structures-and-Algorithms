Node *sortedInsert(struct Node* head, int data) {
        Node* newNode = new Node(data);
        if(head == nullptr){
            return newNode;
        }
        else{
            if(data < head->data){
                newNode->next = head;
                return newNode;
            }
            
            Node* prev = head;
            Node* curr = head->next;
            
            while(curr!=nullptr){
                if(data < curr->data){
                    prev->next = newNode;
                    newNode->next = curr;
                    return head;
                }
                
                prev = curr;
                curr = curr->next;
            }
            
            if(prev->next == nullptr){
                prev->next = newNode;
            }
            
            return head;
        }
    }