# Print Bracket Number
## Question

https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:
```
Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.

Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
```
Expected Time Complexity: O(|str|)<br>
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105<br>
str contains lowercase English alphabets, and '(', ')' characters
At any index, the number of opening brackets is greater than or equal to closing brackets

## Approach
We can use a stack here:
1. Create a stack and initialize the last bracket number as 0;
2. If an opening bracket is found - increment the current bracket number and push it to the ans array and stack
3. If the closing bracket is found pop the stack and push it to the ans. 
4. Return the ans

## Code
```cpp
vector<int> bracketNumbers(string str) {
        vector<int> ans;
        stack<int> s;
        int b = 0;
        
        for(auto i : str){
            if(i == '('){
                b++;
                ans.push_back(b);
                s.push(b);
            }
            if(i == ')'){
                ans.push_back(s.top());
                s.pop();
            }
        }
        
        return ans;
    }
```