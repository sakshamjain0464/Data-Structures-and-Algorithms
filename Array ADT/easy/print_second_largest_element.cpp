/*Question - https://www.geeksforgeeks.org/problems/second-largest3735/
Given an array Arr of size N, print second largest distinct element from an array.

Example 1:

Input: 
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the 
array is 35 and the second largest element
is 34.
Example 2:

Input: 
N = 3
Arr[] = {10, 5, 10}
Output: 5
Explanation: The largest element of 
the array is 10 and the second 
largest element is 5.
*/

/*Approach: 
Take two variables - max and secMax
Assign max and secMax to -1
if arr[i] is greater than max, assign max to secMax and arr[i] to max
if arr[i] is greater than secMax but less than max assign arr[i] to secMax
*/

int print2largest(int arr[], int n) {
	    int max = -1;
	    int secMax = -1;
	    
	    for(int i = 0; i<n; i++){
	        if(arr[i] > max){
	            secMax = max;
	            max = arr[i];
	        }
	        else if(arr[i] < max && arr[i] > secMax){
	            secMax = arr[i];
	        }
	    }
	    
	    return secMax;
	    
	}