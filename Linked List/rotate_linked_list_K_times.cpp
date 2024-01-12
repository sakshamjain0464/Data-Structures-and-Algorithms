Node* rotate(Node* head, int k)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            // Getting the Last Node
            Node* curr = head;
            
            while(curr->next != nullptr){
                curr = curr->next;
            }
            Node* last = curr;
            
            // Shift the curr pointer to head to start rotation
            curr = head;
            
            // Let the rotation count be zero and take a temporary node to store the node to be rotated
            int rotationCount = 0;
            Node* temp = nullptr;
            
            // Run the loop for rotations
            while(rotationCount != k){
                Node* temp = curr;        //Take out the head node
                temp->next = nullptr;
                curr = curr->next;       //Shift the current node to the next
                last->next = temp;      //Link the last node with the temporary node    
                last = temp;           //Shift the last pointer to the newly attached node
                rotationCount++;      
            }
            
            return curr;             //Return the current pointer becauseit is pointing towards the head node of the rotated lis
        }
    }