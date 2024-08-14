# Square Root of a number

## Question
https://www.geeksforgeeks.org/problems/square-root/1

Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number
```
Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
```

Expected Time Complexity: O(logn)<br>
Expected Auxiliary Space: O(1)


Constraints:<br>
1 ≤ n ≤ 107

## Approach
The square of a number is
```n*n```.
We can search a number from 1 to n, if the square of the number is less than or equal to n, we can return our answer.

### Approach 1 - Linear Search
1. We can search 1 to n and return the largest possible number whose square is less than equal to n

#### Code
```cpp
long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int ans = 1;
        for(int i = 1; i<n; i++){
            if(i*i <= n){
                ans = i;
            }
            else break;
        }
        return ans;
}
```

**Time Complexity - O(n)**
**Space Complexity - O(1)**

### Approach 2 - Binary Search
1. We can search 1 to n and return the largest possible number whose square is less than equal to n.
2. Take two variables ```high=n``` and ```low=1```
3. Traverse till low is less than or equal to high.
    1. Take the mid value.
    2. If ```mid*mid <= n``` then high should be ```mid-1```.
    3. else low should be ```mid+1```.
4. High will store the ans.

Reference - https://www.youtube.com/watch?v=Bsv3FPUX_BA
#### Code
```cpp
long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int high = n;
        long long int low = 1;
        
        while(low <= high){
            long long int mid =(low+high)/2;
            if(mid*mid <= n){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
         return high;
    }
```

