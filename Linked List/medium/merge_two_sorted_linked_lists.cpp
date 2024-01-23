Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == nullptr){       //If first list is empty
        return head2;
    }
    if(head2 == nullptr){       //If second list is empty
        return head1;
    }
    
    //Initialize two pointers
        Node* first = nullptr;       
        Node* second = nullptr;
        
    // The two pointers are taken because , we will merge the list whose first element is greater
    // to the list whose first element is greater
        
        if(head1->data < head2->data){
            first = head1;
            second = head2;
        }
        else{
            first = head2;
            second = head1;
        }
        
        
        // Take two pinters for each list
        Node* curr1 = first;
        Node* next1 = first->next;
        Node* curr2 = second;
        Node* next2 = second->next;
        
        //If the first list contains one element CORNER CASE
        if(first->next == nullptr){
            first->next = second;
            return first;
        }
        
        
        
        while(next1 != nullptr && curr2 != nullptr){
            if(curr2->data <= next1->data && curr2->data >= curr1->data){ //If the node can be inserted
                curr1->next = curr2;         
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            }
            else{              //Else Move ahead
                curr1 = next1;
                next1 = curr1->next;
                
                if(next1 == nullptr){    //If the first list goes empty and the second list is remaining attach the remaining list to the first list
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }