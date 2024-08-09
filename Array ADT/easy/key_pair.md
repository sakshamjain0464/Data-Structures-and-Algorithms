# Key Pair
## Question
https://www.geeksforgeeks.org/problems/key-pair5616/1

Given an array arr of positive integers and another number x. Determine whether two elements exist in arr whose sum is exactly x or not. Return a boolean value true if two elements exist in arr else return false.
```
Examples:

Input: x = 16, arr[] = [1, 4, 45, 6, 10, 8]
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16
Input: x = 11, arr[] = [1, 2, 4, 3, 6]
Output: false
Explanation: None of the pair makes a sum of 11
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

Constraints:<br>
1 ≤ arr.size ≤ 10<sup>5</sup><br>
1 ≤ arr[i] ≤ 10<sup>5</sup>


## Using HashMap
1. Take a hashmap.
2. Iterate the array if **x-i** is already present in the map, return true.
### Code
```cpp
bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        // code here
        unordered_map<int, bool> m;
        
        for(auto i : arr){
            if(m[x-i] == true) return true;
            m[i] = true;
        }
        
        return false;
    }
```

**Time Complexity : O(n)**<br>
**Space Complexity : O(n)**

## Using Sorting
1. Sort the array.
2. Using two-pointer approach, take two pointers on start and end:
    - if the ```x == start+end``` -->  return true
    -  if ```x < start+end``` ---> take end to back
    - if ```x > start+end``` ---> take start ahead.

```cpp
bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        // code here
        sort(arr.begin(), arr.end());
        
        int start = 0, end = arr.size()-1;
        while(start < end){
            int sum = arr[start] + arr[end];
            if(sum == x) return true;
            if(sum < x) start++;
            if(sum > x) end--;
        }
        return false;
    }
```
**Time Complexity : O(nlogn)**<br>
**Space Complexity : O(1)**



