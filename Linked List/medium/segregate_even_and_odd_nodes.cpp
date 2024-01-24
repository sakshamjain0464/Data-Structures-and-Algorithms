/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers 
so they appear first and 17,15,9 are odd 
numbers that appear later.
*/

/*
Approach - Create head and tail pointers for odd and even lists, traverse the list and if node is even attach to even list, if node is odd attach to odd list.
Now attach the odd list at the end of even list.
If the even list is empty return the odd list.
*/
Node* divide(int N, Node *head){
        if(head == nullptr){
            return head;
        }
        
        //Take head and tail for even and odd lists
        
        Node* curr = head;
        Node* even = nullptr;
        Node* evenTail = nullptr;
        Node* odd = nullptr;
        Node* oddTail = nullptr;
        Node* next = curr->next;
        Node* temp = nullptr;
        
        while(curr != nullptr){
            temp = curr;
            next = curr->next;
            temp->next = nullptr;
            if(curr->data%2 == 0){
                if(even == nullptr){
                    even = temp;
                    evenTail = temp;
                }
                else{
                    evenTail->next = temp;
                    evenTail = temp;
                }
            }
            else{
                if(odd == nullptr){
                    odd = temp;
                    oddTail = temp;
                }
                else{
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            curr = next;
        }
        
        if(even == nullptr){  //If the even list is null;
            return odd;
        }
        
        evenTail->next = odd;
        return even;
    }