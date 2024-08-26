# Book Allocation Problem
## Question

https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
```
Examples:

Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: n = 3, arr[] = [15, 17, 20], m = 5
Output: -1
```

Explanation: Allocation can not be done.<br>
Expected Time Complexity: O(n logn)<br>
Expected Auxilliary Space: O(1)

Constraints:<br>
1 <=  n, m <= 105<br>
1 <= arr[i] <= 106               

## Approach
**Reference -  https://www.youtube.com/watch?v=YTTdLgyqOLY**

We need to allocate some pages to every student, and the maximum pages allocated must be minimum of all the possible allocations.

The minimum number of pages we can allocate is the minimum value present in the array.

The maximum number of pages we can allocate to one student is all the pages, i.e. the sum of all pages.

Hence, we can say that our allocation lies between minimum pages and maximum pages.

We need to search between the two values and if it is a possible solution and it is minimum of all possible solutions we can return it.

### 1. Using Linear Search
1. Find the search space.
2. Iterate the array, if any value is a possible solution return it.

#### Code 
```cpp
long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m) return -1;
        long long sum = 0;
        int start = INT_MAX;
        
        for(long long i = 0; i<n; i++){
            start = min(start, arr[i]);
            sum+=arr[i];
        }
        
        for(int i = start; i<=sum; i++){
            if(isPossibleSolution(n, arr, m, i)) return i;
        }
        
        // return ans;
    }
```

### 2. Using Binary Search
1. Find the Search space.
2. Start searching the search space:
    - if mid is the possible solution, store it to an ```ans``` variable.
    - Now all the values after mid are greater hence there is no point searching, hence ```end = mid-1```.
    - if mid is not a possible solution, hence all the values before mid are also not possible, hence ```start = mid+1```.

#### Code
```cpp
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m) return -1;
        long long sum = 0;
        int start = INT_MAX;
        
        for(long long i = 0; i<n; i++){
            start = min(start, arr[i]);
            sum+=arr[i];
        }
        
        long long ans = -1;
        long long end = sum;
        
        long long mid = start + (end-start)/2;
        
        while(start <= end){
            if(isPossibleSolution(n, arr, m, mid)){
                // cout<<start<<"  "<<end<<"  "<<mid<<endl;
                ans = mid;
                end = mid-1;
            }
            else{
                // cout<<start<<"  "<<end<<"  "<<mid<<endl;
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        
        return ans;
    }
```

## Checking for possible solution.
We need to check if any value we are considering is a possible solution or not.

So we will start with one student and start allocating him pages.

If the number of pages allocated to student is greater than assumed value, we will move to next student.

If we allocated all the given values of array to desired number of students, without any student exceeding our assumed value, our assumed value will be the possible solution.

### Approach
1. Initialize the first student ```studentCount = 1``` and ```pageSum = 0```.
2. Start Iterating the array:
    - If ```pageSum + currentPages <= desired_value```, this means we can allocate these pages to a student, hence add ```currentPages``` to  ```pageSum```.
    - If ```pageSum + currentPages > desired_value```, we have to move to next student:
        - Increment the ```studentCount```.
        - Check if the ```studentCount``` exceeds the desired number of students, if yes the assumed value is not a possible solution
        - If the ```currentPages``` value is greater than the assumed value, it is not a possible solution
        - Set the ```pageSum``` to 0 and add the ```currentPages``` to it.
3. If array is successfully iterated, the assumed value is a possible solution

#### Code
```cpp
bool isPossibleSolution(int n, int arr[], int m, long long mid){
      long long pageSum = 0;
      int studentCount = 1;
      for(int i = 0; i<n; i++){
          if(pageSum + arr[i] <= mid){
              pageSum += arr[i];
          }
          else{
              studentCount++;
              if(studentCount > m || arr[i] > mid) return false;
              pageSum = arr[i];
          }
      }
      return true;
  } 
  
```