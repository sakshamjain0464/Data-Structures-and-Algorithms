# Subtract two numbers represented by linked list

## Question

https://www.geeksforgeeks.org/problems/subtraction-in-linked-list

You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

**Example 1:**

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:  
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.
Example 2:

**Input:**
L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation: 
First linked list represents 0063 => 63 and 
the second one represents 710. 63 subtracted 
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.

**Your Task:**
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10
0 <= values represented by the linked lists < 10


## Intuition
1. Remove all the trailing zeros from both numbers.
2. Large numbers are Subtracted from small numbers. (Find Out Which Number is Larger)
3. Reverse both the lists.
4. Subtract the digits one by one from reverse.
5. If the digit in the large number is greater, subtract 1 from the next digit and add 10 to the current digit(taking carry).
6. Reverse the answer list and remove trailing zeros from the answer list.

## Approach
1. Remove all the trailing zeros from both lists using removeTrailingZeros Function.
2. If both the lists are empty after removing trailing zeros return a node containing zeros.
3. If one list is null return the another list.
4. Get the larger and smaller list from a getLarge Function.
5. Reverse both lists.
6. Iterate till one list ends.
```bash
            if(large->digit < small->digit){
                subtract 1 from next digit of large
                add 10 to current digit
                subtract both digits and add to the answer list
            }
            else{
                subtract both digits and add to the answer list
            }
```
7. If the large list is not completed, add it to answer list.
8. Reverse the answer list and remove trailing zeros.
9. Return the answer list.

![Solution]()

## Code 
```cpp
     // Function to get length
    int getLength(Node* &head){
        int len = 1;
        Node* curr = head;
        
        while(curr != nullptr){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    // Function to get large number
    Node* getLarge(Node* &head1, Node* &head2){
        
        int len1 = getLength(head1);
        Node* curr1 = head1;
        int len2 = getLength(head2);
        Node* curr2 = head2;
        
        if(len1 > len2){
            return head1;
        }
        if(len2 > len1){
            return head2;
        }
        
        while(curr1 != nullptr && curr2 != nullptr){
            if(curr1->data > curr2->data){
                return head1;
            }
            if(curr2->data > curr1->data){
                return head2;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        // If both numbers are equal
        return nullptr;
    }
    
    // FUnction to reverse
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
    
    
    // Function to remove trailing zeros
    Node* removeTrailingZeros(Node* &head){
        bool trailingZeros = true;
        
        while(trailingZeros && head != nullptr){
            if(head->data != 0){
                trailingZeros = false;
            }
            else{
                head = head->next;
            }
        }
        
    }
    
    
    // Function to insert at tail
    Node* insertAtTail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head == nullptr){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        // Removed trailing zeros
        removeTrailingZeros(head1);
        removeTrailingZeros(head2);
        
        // If both lists only contain trailing zeros
        if(head1 == nullptr && head2 == nullptr){
            Node *temp = new Node(0);
            return temp;
        }
        if(head1 == nullptr){
            return head2;
        }
        if(head2 == nullptr){
            return head1;
        }
        else{
            // Get the large and small lists
            Node* large = getLarge(head1, head2);
            
            // Assign the small list on the basis of the large list
            Node* small = (large == head1)?head2:head1;
            Node* ans = nullptr;
            Node* ansTail = nullptr;

            // If both numbers are equal
            if(large == nullptr){
                Node *temp = new Node(0);
                return temp;
            }
            
            // Reverse the lists
            large = reverse(large);
            small = reverse(small);
            
            // subtraction
            while(small != nullptr && large != nullptr){
                if(small -> data > large->data){
                    // Taking carry
                    large->next->data = large->next->data-1;
                    large->data = large->data + 10;
                    int sub = large->data - small->data;
                    insertAtTail(ans, ansTail, sub);
                }
                else{
                    int sub = large->data-small->data;
                    insertAtTail(ans, ansTail, sub);
                }
                large = large->next;
                small = small->next;
            }
            
            // Appending large list to ans
            while(large != nullptr){
                // If the first digit of the large list is negative(Corner Case)
                if(large->data < 0){
                    large->next->data = large->next->data-1;
                    large->data = large->data + 10;
                }
                insertAtTail(ans, ansTail, large->data);
                large = large->next;
            }
            
            // Reverse the answer
            ans = reverse(ans);
            
            // Remove trailing zeros from answer
            removeTrailingZeros(ans);
            
            return ans;
        }
    }
```

## Helping Function Description
1. **getLarge()** - Takes the head of both lists and return which list contails large number.
    - We can say a number as large from another number as
        - its length is greater than another number
        - If the lengths are equal, we can check whose digit is large.
        ```bash 
                len1 = length of num1
                len2 = length of num2
                if(len1 > len2){
                    return len1;
                }
                if(len2 > len1){
                    return len2;
                }

                traverse(both numbers){
                    if(digit1 > digit2){
                        return num1
                    }
                    if(digit1 < digit2){
                        return num2
                    }
                    move ahead in both numbers
                }

                if both numbers reach till end both are equal
                then return null
        ```

2. **removeTrailingZeros()** - Takes the head of a linked list and remove all the trailing zeros.
    - Consider that the number contains trailing zeros.
    - Start iterating till we get that there are no trailing zeros ahead.
    - If we find any number greater than zero, we can now say that there are no trailing zeros ahead.
    ```bash
        bool hasTrailingZeros =  true
        while(hasTrailingZeros){
            if(current Digit != 0){
                hasTrailingZeros = false
            }
            remove trailing zero node
        }
    ```

3. **getLength()** - returns length of a list.
4. **reverse()** - reverse a list.
5. **insertAtTail()** - inserts a new node at tail.

## Corner Cases
### Case
```bash
    4
    1024
    2
    34
    Your Output: 
    1-190
    Expected Output: 
    990
```
This will come if we, do not check if the element of the large list is negative or not.
If it is negative it will push -1 to the answer list

If it is negative we will have to take carry and then push it.