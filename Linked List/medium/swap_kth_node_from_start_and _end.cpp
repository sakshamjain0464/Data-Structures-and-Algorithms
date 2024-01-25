/*Question : Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

Example 1:

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after
swapping the 1st node from the beginning
and end thenew list will be 4 2 3 1.
 

Example 2:

Input:
N = 5,  K = 7
value[] = {1,2,3,4,5}
Output: 1
Explanation: K > N. Swapping is invalid. 
Return the head node as it is.
*/

/*Approach : 
1.) If K > num return the original list.
2.) Calculate which node is the kth node from last by counting from start using num-K+1.
3.) Reach to the kth and kth from last nodes while storing their previous nodes.
4.) If the previous of kth from start is available put its next to kth from last and if the previous of Kth from last is available then put its next to kth from start.
5.) Swap the next nodes of both the Kth nodes.
6.) If K is 1, return the kth from last.
7.) If the K and num are equal return Kth start.
8.) In other cases return the head of the list.
*/

Node *swapkthnode(Node* head, int num, int K)
{
    if(head == nullptr || head->next == nullptr || K>num){
        return head;      //
    }
    
    
    int count = 1;  //Take a count variable for iteration
    
    Node* curr1 = head;
    Node* curr2 = head;
    Node* prev1 = nullptr;
    Node* prev2 = nullptr;
    
    int kLast = num - K + 1;       //For calculating Kth variable from last
     
    while(count < K){          //Reach to Kth node from start
        prev1 = curr1;
        curr1 = curr1->next;
        count++;
    }
    
    
    count = 1;
    while(count < kLast){            //Reach to Kth node from last
        prev2 = curr2;
        curr2 = curr2->next;
        count++;
    }
    
    
    // Swapping Logic
    
    if(prev1 != nullptr){
        prev1->next = curr2;
    }
    if(prev2 != nullptr){
        prev2->next = curr1;
    }
    
    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
    
    if(K == 1){
        return curr2;
    }
    
    if(K==num){
        return curr1;
    }
    
    return head;
}