Node* segregate(Node *head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        else{
            // We have 3 values, hence we will take an array to store count of occurrance of each element
            int arr[3] = {0};
            
            // Store the count of occurance of each element
            Node* curr = head;
            while(curr != nullptr){
                arr[curr->data]++;
                curr = curr->next;
            }
            
            // Initialize a new list
            curr = nullptr;
            Node* tail = nullptr;
            
            // Append the element number of times it is occurring
            for(int i = 0; i<3; i++){
                while(arr[i] != 0){
                    Node* temp = new Node(i);
                    arr[i]--;
                    if(curr == nullptr){
                        curr = temp;
                        tail = temp;
                    }
                    else{
                        tail->next = temp;
                        tail = temp;
                    }
                }
            }
            
            // Return the head of the new list
            return curr;
        }
    }