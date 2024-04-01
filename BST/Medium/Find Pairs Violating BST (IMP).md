# Find Pairs Violating BST

## Question
Given a binary tree with n nodes, find the number of pairs violating the BST property.
BST has the following properties:-

Every node is greater than its left child and less than its right child.
Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
The maximum in the left sub-tree must be less than the minimum in the right subtree.
Example 1:

Input : 

n = 5

Input tree
    
![INPUT TREE](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861883/Web/Other/blobid0_1709054479.png)

Output :
5
```
Explanation : 
Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
```
Example 2:

Input : 

n = 6

Input tree

![INPUT TREE](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861883/Web/Other/blobid1_1709055216.png)

Output :
8

Explanation :

There are total 8 Pairs which violation the BST properties.

Your task :

You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.
 
Expected Time Complexity: O(n*logn)

Expected Space Complexity: O(n)
 
Your Task :
1 <= n <= 2*104

-109 <= node->data <= 109

## Approach 
1. Find Inorder Traversal
2. Find Inversion count of the array using merge sort


## HELP!
https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

https://www.youtube.com/watch?v=AseUmwVNaoY&t=1098s

## Code
```cpp
void traverse(Node* root, vector<int> &in){
      if(root){
          traverse(root->left, in);
          in.push_back(root->data);
          traverse(root->right, in);
      }
  }
  
  int mergeSort(vector<int> &in, int start, int end){
      int inv = 0;
      
      if(start < end){
         int mid = start + (end-start)/2;
         inv+= mergeSort(in, start, mid);
         inv+= mergeSort(in, mid+1, end);
         inv+= merge(in, start, mid,end);
      }
      
      return inv;
  }
  
  int merge(vector<int> &in, int start, int mid, int end){
      int a = start;
      int b = mid+1;
      
      int inv = 0;
      
      vector<int> temp;
      
      while(a <= mid && b<=end){
          if(in[a] <= in[b]) temp.push_back(in[a++]);
          else {
              temp.push_back(in[b++]);
              inv += mid - a + 1;
          }
      }
      
      while(a <= mid){
          temp.push_back(in[a++]);
      }
      
      while(b <= end){
          temp.push_back(in[b++]);
      }
      
      int z = 0;
      
      for(int i = start; i<= end; i++){
          in[i] = temp[z++];
      }
      
      return inv;
  }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        vector<int> inorder;
        traverse(root, inorder);
        
        int invCount = mergeSort(inorder, 0, n-1);
        
        return invCount;
    }
```