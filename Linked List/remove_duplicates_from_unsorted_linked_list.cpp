Node * removeDuplicates( Node *head) 
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            map<int, bool> visit;
            
            Node* curr = head;
            visit[head->data] = true;
            
            while(curr->next != nullptr){
                if(visit[curr->next->data]){
                    curr->next = curr->next->next;
                }
                else{
                    visit[curr->next->data] = true;
                    curr = curr->next;
                }
            }
            return head;
        }
    }