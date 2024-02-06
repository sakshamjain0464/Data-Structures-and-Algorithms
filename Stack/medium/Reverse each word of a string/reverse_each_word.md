# Reverse Each word of a Stack

https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/

Given a String. Reverse each word in it where the words are separated by dots.<br>

**Example 1:**<br>

**Input:**
S = "i.like.this.program.very.much"<br>
**Output:** <br>
i.ekil.siht.margorp.yrev.hcum<br>
**Explanation:** <br>
The words are reversed as
follows:<br>"i" -> "i",<br>"like"->"ekil",<br>
"this"->"siht",<br>"program" -> "margorp",<br>
"very" -> "yrev"<br>,"much" -> "hcum".<br>

**Example 2:**

**Input:** <br>
S = "pqr.mno"<br>
**Output:**
rqp.onm<br>
**Explanation:**<br>
The words are reversed as
follows:<br>"pqr" -> "rqp" ,
"mno" -> "onm"

**Your Task:**<br>
You don't need to read input or print anything. Your task is to complete the functionreverseWords()which takes the string S as input and returns the resultant string by reversing all the words separated by dots.

Expected Time Complexity:O(|S|).<br>
Expected Auxiliary Space:O(|S|).

Constraints:<br>
1<=|S|<=105

## Approach

1. Take an ans string and a stack.
2. Iterate the string
   1. If the current character is a '.', pop each element from stack and push it to ans.
   2. Push a '.' to the stack.
   3. Else push the character to stack.
3. pop each element from stack and push it to ans.(for the last word)
4. Return the answer

## Code

```cpp
    string reverseWords (string s)
    {
        stack<char> st;
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '.'){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back('.');
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }

        return ans;
    }
```
