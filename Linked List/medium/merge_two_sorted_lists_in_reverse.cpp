/*Question : Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.

Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
*/

/*Approach - 
1.) Reverse both the lists so that both of them are in sorted reverse order.
2.) If any of the list is empty return another one.
3.) Take head and tail pointers of the answer list.
4.) Iterate the lists, if the data of the node first list is grater than the other list add that node to the answer list and move the current pointer of the first list to next node, else insert the node of second list to the answer and move its next pointer to its next node.
5.) If any of the lists is remaining add it to the end of anwer list.
6.) Return the answer list.
*/

struct Node* reverseList(Node *head){        //Function for reversing the lists
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail, Node* &dataNode){   //For inserting the node to the merged list
        dataNode->next = nullptr;
        if(head == nullptr){
            head = dataNode;
            tail = dataNode;
        }
        else{
            tail->next = dataNode;
            tail = tail->next;
        }
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        //Taking head and tail pointer for merged lists
        Node* merged = nullptr;
        Node *mergedTail = nullptr;
        
        // Reverse both lists
        Node* curr1 = reverseList(node1);
        Node* curr2 = reverseList(node2);
        
        
        // If any of the lists is null return another
        if(curr1 == nullptr){
            return curr2;
        }
        if(curr2 == nullptr){
            return curr1;
        }
        
        // Pointers to store the next pointer so that any of the lists is not lost
        Node* next1 = curr1->next;
        Node* next2 = curr2->next;
        
        // Iterate the lists
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->data >= curr2->data){
                next1 = curr1->next;
                insertAtTail(merged, mergedTail, curr1);
                curr1 = next1;
            }
            else{
                next2 = curr2->next;
                insertAtTail(merged, mergedTail, curr2);
                curr2 = next2;
            }
        }
        
        
        // if any of the list is left insert it at the end of the merged list
        if(curr1 == nullptr){  
            mergedTail->next = curr2;
        }
        else{
            mergedTail->next = curr1;
        }
        
        // Return the answer
        
        return merged;
        
    }  