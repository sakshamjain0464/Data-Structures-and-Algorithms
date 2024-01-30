/*
Question - https://www.geeksforgeeks.org/problems/queue-using-two-stacks/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions

Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Note :- If there is no element return -1 as answer while popping.

Example 1:

Input:
5
1 2 1 3 2 1 4 2

Output: 
2 3

Explanation: 
In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue 
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.
Example 2:

Input:
4
1 2 2 2 1 4

Output: 
2 -1

Explanation: 
In the second testcase 
1 2 the queue will be {2}
2   poped element will be 2 and 
    then the queue will be empty
2   the queue is empty and hence -1
1 4 the queue will be {4}.
Your Task:
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue and pop which returns a integer poped out from other queue(-1 if the queue is empty). The printing is done automatically by the driver code.

Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()  
Expected Auxilliary Space : O(1).

Constraints:
1 <= Q <= 100
1 <= x <= 100
*/

/*Approach:
We have two stacks.
In push operation take all the elements of stack2 into stack1 and then push the new element, then pop each element from stack1 and push to stack 2.
In pop operation - if(stack2 is empty){
    return -1
}
else{
    pop stack 2 and return the data
}
*/


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    while(s1.empty() != true){
        s1.pop();
    }
    
    while(s2.empty() != true){
        s1.push(s2.top());
        s2.pop();
    }
    
    s1.push(x);
    
    while(s1.empty() != true){
        s2.push(s1.top());
        s1.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s2.empty() == true){
        return -1;
    }
    int data = s2.top();
    s2.pop();
    return data;
}