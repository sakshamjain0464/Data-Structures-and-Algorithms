int countNodesinLoop(struct Node *head)
{
    if(head->next == nullptr){ //If the list is empty!  
        return 0;
    }
    if(head->next == head){ //If the head points itself
        return 1;
    }
    else{
        // Finding the start of loop
        // Initialize the pointers
        Node* fast = head;
        Node* slow = head;
        
        // Search for the point of intersection
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            // If intersection is found
            if(fast == slow ){
                break;
            }
        }
        
        // If the list has no loop
        if(fast == nullptr || fast->next == nullptr){
            return 0;
        }
        
        // Put slow to head amd move both pointers by one step
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        
        // Start Counting until we reach the start of loop again.
        fast = fast->next;
        int count = 1;
        while(fast!=slow){
            fast = fast->next;
            count++;
        }
        
        return count;
    }