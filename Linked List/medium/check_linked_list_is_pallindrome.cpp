/*
Question : Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
Case 1: 
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

Case 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
*/

/*
Approach 1 : Take an array, store each element in an array, compare each element with the list by reverse traversing the array.
*/

bool isPalindrome(Node *head){
        if(head == nullptr || head->next == nullptr){
            return true;                  //If the list contains only one element it is considerd pallindrome
        }
        
        vector<int> temp;         //Take a vector
        Node* curr = head;
        while(curr != nullptr){  //Copy the list to the array
            temp.push_back(curr->data);
            curr = curr->next;
        }
        
        curr = head;
        
        
        // Reverse traverse the array and compare each element with each element of the list
        for(int i = temp.size()-1;i>=0; i--){
            if(temp[i] != curr->data){
                return false;
            }
            curr = curr->next;
        }
        
        return true;
        
    }


/*
Approach 2 :
1.) Find the middle of the list.
2.) Reverse the list after the middle node
3.) Take one pointer on start and second pointer on start of the reversed list
4.) Compare Both the Lists.
*/

Node* reverse(Node* head){
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
    
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head == nullptr || head->next == nullptr){
            return true;                  //If the list contains only one element it is considerd pallindrome
        }
        
        Node* middle = findMid(head);    //Find the middle of the list
        Node* temp = middle->next;       
        middle->next = reverse(temp);   //Reverse the list after the middle node
        
        Node* head1 = head;
        Node* head2 = middle->next;   //Compare both the lists
        
        while(head2 != nullptr){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return true;
        
        
    }