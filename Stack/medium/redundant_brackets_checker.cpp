/*
Question - https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print Yes if redundant, else No.
Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

Example 1:

Input:
exp = ((a+b))
Output:
Yes
Explanation:
((a+b)) can reduced to (a+b).
Example 2:

Input:
exp = (a+b+(c+d))
Output:
No
Explanation:
(a+b+(c+d)) doesn't have any redundant or multiple
brackets.
*/

/*Approach 
1.) Take a Stack
2.)Iterate over the string
        if(opening bracket or any operator is found){
            push into stack.
        }
        else{
            if(closing bracket is found){
                consider that the bracket is redundant
                iterate the stack until the corresponding opening bracket is not found
                    if(the top of the stack is an operatoer){
                        mark the bracket as non redundant and pop that element
                    }

                if(the bracket is still marked as redundant){
                    the string contains redundant brackets hece return false.
                }

                remove that opening bracket also
            }
        }

3.) If the string ends without returnibg true, the string contains no redundant brackets hence return false
*/


int checkRedundancy(string s) {
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                    bool redundant = true;
                    
                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '+' || top == '-' || top == '*' || top == '/'){
                            redundant = false;
                        }
                        st.pop();
                    }
                    
                    if(redundant == true){
                        return true;
                    }
                    st.pop();
                }
            }
        }
        return false;
    }