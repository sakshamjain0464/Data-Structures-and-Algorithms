# Three Way Partitioning
## Question
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.

The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is 1 if you modify the given array successfully.

Geeky Challenge: Solve this problem in O(n) time complexity.
```
Example 1:

Input: 
n = 5
array[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 
1
Explanation: 
One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be 1.
```
```
Example 2:

Input: 
n = 6 
array[] = {1, 4, 3, 6, 2, 1}
[a, b] = [1, 3]
Output: 
1
Explanation: 
One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be 1.
```

Your Task:<br>
You don't need to read input or print anything. The task is to complete the function threeWayPartition() which takes the array array, a, and b as input parameters and modifies the array in place according to the given conditions.

Expected Time Complexity: O(n)<br>
Expected Auxiliary Space: O(1)

Constraints:<br>
1 <= n <= 10<sup>6</sup><br>
1 <= array[i], a, b <= 10<sup>9</sup>


## Approach O(n)
1. Take three pointers start, end and temp (for iterating);
2. Iterate using temp
```
        if(temp is below range){
            swap(start++, temp++)
        }
        else if(temp lies in range){
            temp++
        }
        else{     // temp is above range
            swap(temp, end--)
        }
```


## Code
```cpp
void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int start = 0, temp = 0, end = arr.size()-1;
        
        while(temp <= end){
            if(arr[temp] < a){
                swap(arr[temp++], arr[start++]);
            }
            else if(arr[temp] >= a && arr[temp] <= b){
                temp++;
            }
            else{
                swap(arr[temp], arr[end--]);
            }
        }
        
    }
```