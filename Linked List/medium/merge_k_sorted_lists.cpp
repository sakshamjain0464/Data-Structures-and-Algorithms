/*Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
*/

/*Approach - Take an empty answer list, merge each given list in the array with the answer list* by merging two sorted lists*/
Node* mregeTwoSortedLists(Node* head1, Node* head2){
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
  
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
          Node* ans = nullptr;
          
          for(int i = 0; i<K; i++){
              ans = mregeTwoSortedLists(ans, arr[i]);
          }
          
          return ans;
    }