/*
Question - https://www.geeksforgeeks.org/problems/valid-substring0624/1
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid
substring is "()(())". Length = 6.

Your Task:
You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.


Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)

*/

/*
Approach -
1.) Take a stack and answer variable = 0.
2.) Start traversing.
3.) if(stack is empty || ch == '(' || ch == ')') push[i]
4.) if(ch == ')') pop()
    if(stack is empty) take max(ans , i+1) (because if stack is empty the substring is valid from start until the current index)
    if(!stack is empty) take max(ans, i-st.top()) (If the substring breaks due to extra parenthesis, we have the starting index of new substring at top of the stack, we can calculate the length of the new substring by subracting current index from the starting point of the new substring, if the length of new substring is greater than ans which is the length of old sybstring, then we can assign it to our ans)
5. Return Ans

Sample Custom Case - ())))())))()()()()()()()))
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int findMaxLen(string s)
{
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() || s[i] == '(' || s[st.top()] == ')')
        {
            st.push(i);
        }
        else
        {
            st.pop();
        }
        if (st.empty())
        {
            ans = max(ans, i + 1);
        }
        else
        {
            ans = max(ans, i - st.top());
        }
    }

    return ans;
}