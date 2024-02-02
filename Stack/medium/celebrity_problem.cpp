/*
!IMPORTANT
Question - https://www.geeksforgeeks.org/problems/the-celebrity-problem/
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1
*/

/*
Simplification:
If all the elements of the row of the corresponding index are zeros and all the elements of the corresponding index are 1 except its own, is a celebrity
If the person knows no-one and everyone knows him, means he is a celebrity.
M[i][i] is always zero
*/

/*

Approach:
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}} == >> {     0 1 2
                           0 {0,1,0}
                           1 {0,0,0}
                           2 {0,1,0}
                        }
1.) Take a stack to take the account of all the potential candidates and push all the indices into it ==> [2,1,0];
2.) Pop out top two elements A and B and check who among them is a potential candidate(A potential candidate does not know another one)==>
if(A knows B) ==> A is not a celebrity hence push B to the stack because it is still a potential cadidate to be a celibrity
if(B knows A) ==> B is not a potential candidate, push A
3.) Repeat step 2 until there is only one element left in the stack.
4.) Consider the one left element in stack as the answer and  check whether it has n zeros in its column and n-1 ones in its rows.
5.)If the condition in the above step staisfies, return the answer, else return -1.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int ans = s.top();
    int zeros = 0;
    int ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
            zeros++;
        if (M[i][ans] == 1)
            ones++;
    }

    if (zeros == n && ones == n - 1)
    {
        return ans;
    }

    return -1;
}