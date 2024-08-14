# Spiral Print a Matrix
## Question
https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:
```

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
```

Expected Time Complexity: O(n2)<br>
Expected Auxiliary Space: O(n2)

Constraints:<br>
1 <= matrix.size(), matrix[0].size() <= 100<br>
0 <= matrix[i][j]<= 100


## Using Loops
1. Take four pointers ```top = 0```, ```left = 0```, ```right = m-1```, ```bottom = n-1```.
2. Traverse the first line of the matrix, then increment top.
3. Traverse the last column of the matrix and decrement right.
4. Traverse the last line of the matrix then decrement bottom.
5. Traverse the first column of the matrix the increment right.
6. Complete the process from 2-5, till top and bottom are at same place and left and right are at same place.


```cpp
vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        vector<int> ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0, bottom = n-1, left = 0, right = m-1;
        
        while(top <= bottom && left <= right){
            for(int i = left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i = top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            }
            bottom--;
            if(left <= right){
                for(int i = bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            }
            left++;
        }
        
        return ans;
    }
```

**Time Complexity : O(n<sup>2</sup>)**<br>
**Space Complexity : O(n<sup>2</sup>)**






