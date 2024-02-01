/*
Question - https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/

You are given N elements and your task is to Implement a Stack in which you can get a minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1
Your Task:
You are required to complete the three methods push() which takes one argument an integer 'x' to be pushed into the stack, pop() which returns an integer popped out from the stack, and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity: O(1) for all the 3 methods.
Expected Auxiliary Space: O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/

/*Approach - */

int minEle;
stack<int> s;

public:
/*returns min element from stack*/
int getMin()
{

    if (s.empty())
        return -1;

    return minEle;
}

/*returns poped element from stack*/
int pop()
{

    if (s.empty())
    {
        return -1;
    }

    int data = s.top();
    s.pop();
    if (data > minEle)
    {
        return data;
    }
    else
    {
        int prevMin = minEle;
        int val = 2 * minEle - data;
        minEle = val;
        return prevMin;
    }
}

/*push element x into the stack*/
void push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (x > minEle)
        {
            s.push(x);
        }
        else
        {
            int val = 2 * x - minEle;
            s.push(val);
            minEle = x;
        }
    }
}