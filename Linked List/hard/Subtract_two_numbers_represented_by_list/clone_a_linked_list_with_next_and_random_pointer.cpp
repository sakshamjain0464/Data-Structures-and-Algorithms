/*
https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?page=1&category=Linked%20List&difficulty=Hard&sortBy=submissions
Question : You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b (arb is pointer to random node).

Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding two nodes x and y in the copied list, x.arb --> y.

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer
set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbitrary pointer is set to
node 2.  The second node arbitrary pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.
*/

/*
Approach1 : 
1.) Create a copy of the list.
2.) Create a map which has mapping of the original list node with the corresponding node of the cloned list.
3.) Set the arb node of the cloned list nodes with the corresponding arb node of the original list node.
Video Solution - https://www.youtube.com/watch?v=83mPr0i56Gg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=57
*/

void insertAtTail(Node* &head, Node* &tail, int data){  //For inserting node in the list
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
    
    Node *copyList(Node *head)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        // Create a clone node
        
        Node* clone = nullptr;
        Node* cloneTail = nullptr;
        
        Node* curr = head;
        
        while(curr != nullptr){
            insertAtTail(clone,cloneTail,curr->data);
            curr = curr->next;
        }
        
        unordered_map <Node*, Node*> arbitraryNodeMapping;
        curr = head;
        Node* curr2 = clone;
        
        // Save the mapping of each node with its corresponding node in the cloned list
        while(curr != nullptr && curr2!= nullptr){
            arbitraryNodeMapping[curr] = curr2;
            curr = curr->next;
            curr2 = curr2->next;
        }
        
        
        // Set the arb node of the cloned list to corresponding node of the list
        curr = head;
        curr2 = clone;
        
        while(curr2 != nullptr && curr != nullptr){
            curr2->arb = arbitraryNodeMapping[curr->arb];
            curr = curr->next;
            curr2 = curr2->next;
        }
        
        return clone;
    }



/*
Approach 2:
1.) Clone the list.
2.) Change the links such that the both lists are merged continuously

Original List = 1->2->3->4->x
Cloned List List = 1->2->3->4->x

1->1->2->2->3->3->4->4->x

3.) Copy the arb pointers.

4.) Reverse the link changes of step 2.
*/


void insertAtTail(Node* &head, Node* &tail, int data){  //For inserting node in the list
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
    
    Node *copyList(Node *head)
    {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        // Create a clone node
        
        Node* clone = nullptr;
        Node* cloneTail = nullptr;
        
        Node* curr = head;
        
        while(curr != nullptr){
            insertAtTail(clone,cloneTail,curr->data);
            curr = curr->next;
        }
        
        curr = head;
        Node* curr2 = clone;
        
        // Merge Both the lists
        while(curr != nullptr && curr2 != nullptr){
            Node* next = curr->next;
            curr->next = curr2;
            curr = next;
            
            next = curr2->next;
            curr2->next = curr;
            curr2 = next;
        }
        
        
        // Set the arb node of the cloned list to corresponding node of the list
        curr = head;
        
        while(curr != nullptr){
            if(curr->next != nullptr){
                if(curr->arb != nullptr){
                    curr->next->arb = curr->arb->next;
                }
                else{
                    curr->next->arb = nullptr;
                }
                curr = curr->next->next;
            }
        }
        
        curr = head;
        curr2 = clone;
        
        // Reverse the link changes
        
        while(curr != nullptr && curr2 != nullptr){
            curr->next = curr2->next;
            curr = curr->next;
            
            if(curr != nullptr){
                curr2->next = curr->next;
            }
            curr2 = curr2->next;
        }
        
        return clone;
    }

};