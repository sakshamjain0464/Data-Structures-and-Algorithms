/*
Question - https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output:
3 2 1 4 5
Explanation:
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
Example 2:

Input:
4 4
4 3 2 1
Output:
1 2 3 4
Explanation:
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
Your Task:
Complete the provided function modifyQueue() that takes queue and K as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= K <= N <= 105

*/

/*
Approach - dequeue k elements of queue one by one ane and push into stack
Create a new queue and pop each element and push it to queue till stack is empty
Dequeue ech element of queue and push it to new queue till queue is empty
return the new queue
*/

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;

    int count = 0;
    while (count < k && !q.empty())
    {
        s.push(q.front());
        q.pop();
        count++;
    }

    queue<int> ans;

    while (!s.empty())
    {
        ans.push(s.top());
        s.pop();
    }

    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }

    return ans;
}