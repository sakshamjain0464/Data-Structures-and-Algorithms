Node* findIntersection(Node* head1, Node* head2)
    {
        Node* curr1 = head1; //pointer for first list
        Node* curr2 = head2; //pointer for second list
        vector<int> arr; // array to store the data of first list
        
        //Traverse the first list and store its data into the array
        
        while(curr1 != nullptr){
            arr.push_back(curr1->data);
            curr1 = curr1->next;
        }
        
        //For intersection list
        Node *intersec = nullptr; //head
        Node *intersecTail = nullptr; //tail
        
        int i = 0;   //iterator to traverse array
        
        while(curr2 != nullptr && i<arr.size()){     //if the second list ends or the array is finished
            if(curr2->data == arr[i]){            //if the data is presecnt into both array and list2 insert it into the intersection list
                if(intersec == nullptr){
                    intersec = new Node(curr2->data);
                    intersecTail = intersec;
                }
                else{
                    Node* temp = new Node(curr2->data);
                    intersecTail->next = temp;
                    intersecTail = temp;
                }
                curr2 = curr2->next;      //Move forward in both
                i++;
            }
            else if(curr2->data > arr[i]){      //If the data in list is greater in the list than the data in array move forward in array
                i++;
            }
            else{                   
                curr2 = curr2->next;             //If the data in array is greater in the array than the data in array move forward in list
            }
        }
        
        
        return intersec;
    }