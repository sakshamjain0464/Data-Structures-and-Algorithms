/*
Question - https://www.geeksforgeeks.org/problems/special-stack/
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
 


Your Task:
Since this is a function problem, you don't need to take inputs. You just have to complete 5 functions, push() which takes the stack and an integer x as input and pushes it into the stack; pop() which takes the stack as input and pops out the topmost element from the stack; isEmpty() which takes the stack as input and returns true/false depending upon whether the stack is empty or not; isFull() which takes the stack and the size of the stack as input and returns true/false depending upon whether the stack is full or not (depending upon the
given size); getMin() which takes the stack as input and returns the minimum element of the stack. 
Note: The output of the code will be the value returned by getMin() function.


Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.
*/

/*
Recursive Approach for finding minimum:
Base Case - if(stack is empty)
Alternate Case - get the top and pop the stack
                if(top < min){
                    set min to top
                }

                call again with stack and current minimum

                return minimun
*/

/*
Iterative Approach for finding minimum:
set a min to the top of stack
Pop the stack until it is empty, while popping compare the top;
if(top < min){
            set min to top
        }

return min
*/

void push(stack<int>& s, int a){
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	if(s.size() >= n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.empty()){
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	int data = s.top();
	s.pop();
	return data;
}

int findMin(stack<int>& s, int min){
    if(s.empty()){
        return min;
    }
    else{
        int data = s.top();
        s.pop();
        if(data < min){
            min = data;
        }
        min = findMin(s, min);
        
        return min;
    }
}

int getMin(stack<int>& s){
	// Your code goes here
	
	int min = findMin(s, s.top());
	
	return min;
}