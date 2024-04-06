# Merge Two Binary Heaps
## Question
https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:

Input  : 
n = 4 m = 3

a[] = {10, 5, 6, 2}, 

b[] = {12, 7, 9}

Output : 
{12, 10, 9, 2, 5, 7, 6}

Explanation :
*If images are not being displayed refer to the above link*

![e1](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_1.jpg)
![e2](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_2.jpg)
![e3](https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_3.jpg)

Your Task:  

You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 
Expected Time Complexity: O(n.Logn)

Expected Auxiliary Space: O(n + m)

 

Constraints:
1 <= n, m <= 105

1 <= a[i], b[i] <= 2*105

## Approach:
1. Merge both arrays.
2. BuildHeap using the merged array.

## Code
```cpp
void buildHeap(vector<int> &arr){
        int largest = arr.size()/2 - 1;
        
        for(int i = largest; i>=0; i--){
            heapify(arr, i);
        }
    }
    
    void heapify(vector<int> &arr, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < arr.size() && arr[left] > arr[largest]){
            largest = left;
        }
        
        if(right < arr.size() && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i = 0; i<b.size(); i++){
            a.push_back(b[i]);
        }
        
        buildHeap(a);
        
        return a;
    }
```