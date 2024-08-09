# Find Missing Number
## Question
https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 
```
Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 ```

Constraints:

n == nums.length<br>
1 <= n <= 10<sup>4</sup><br>
0 <= nums[i] <= n<br>
All the numbers of nums are unique.


## Using Sorting
1. Sort the array.
2. Iterate the array 0 to n-1, if any number is not present, return that number.
3. If all the numbers are present return nth number.

```cpp
int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != i) return i;
        }

        return nums.size();
    }
```

**Time Complexity : O(n)**<br>
**Space Complexity : O(1)**

## Using Sum Approach (Optimal)
1. Take the sum of the n numbers.
2. Iterate the array and subtract each number from it.
3. The last remaining number will be the answer.

```cpp
int missingNumber(vector<int>& nums) {
        int n = 0;
        for(int i = 1; i <= nums.size(); i++){
            n+=i;
        }

        for(int i = 0; i < nums.size(); i++){
            n-=nums[i];
        }
        return n;
    }
```

**Time Complexity : O(n)**<br>
**Space Complexity : O(1)**




