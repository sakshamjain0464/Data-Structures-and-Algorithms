# Minimum Difference Between Largest and Smallest Value in Three Moves

## Question
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 
```
Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

```
```
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
```

```
Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
 ```

Constraints:<br>
1 <= nums.length <= 105<br>
-109 <= nums[i] <= 109

## Approach
We need to find the minimum difference b/w smallest and largest element in 3 moves.

We can change only three elements in three moves.

- If the no. of elements is less than or equal to 4 we can make all the elements equal, hence the minimum difference will always be zero.

```
Eg - 5 6 7 8
After three moves:
5 5 5 5 or 6 6 6 6 or 7 7 7 7 or 8 8 8 8 
I all the chances the minimum difference is zero
```

- If the size is greater than 4, we can just use the three smallest and three largest elements of the array and find the minimum difference.

- There can be 4 cases:
    1. Remove the 3 smallest element
    2. Remove the 3 largest element
    3. Remove 2 samllest and 1 largest element
    4. Remove 1 smallest and 2 largest elements,

- We can calculate the minimum differece in all cases and choose minimum of them.

```
Eg- 1 5 0 10 14

After Sorting - 0 1 5 10 14

Apply Case 1,
10 14  ==> 5

Apply Case 2,
0 1   ==> 1

Apply Case 3,
5 10  ==>  5

Apply Case 4,
1 5    ==> 4

Minimum of all cases - 1
Ans - 1
```

## Code
```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size()-1;

        if(n <= 3) return 0;

        int minDiff = INT_MAX;

        minDiff = min(minDiff, nums[n-3] - nums[0]);
        minDiff = min(minDiff, nums[n] - nums[3]);
        minDiff = min(minDiff, nums[n-2] - nums[1]);
        minDiff = min(minDiff, nums[n-1] - nums[2]);

        return minDiff;
    }
};
```