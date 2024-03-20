# Construct Tree from Inorder & Preorder

## Question
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 
Example 1:

Input:

N = 4

inorder[] = {1 6 8 7}

preorder[] = {1 6 7 8}

Output: 8 7 6 1

Example 2:

Input:

N = 6

inorder[] = {3 1 4 0 5 2}

preorder[] = {0 1 3 4 2 5}

Output: 3 4 1 5 2 0

Explanation: The tree will look like
```
       0
    /     \
   1       2
 /   \    /
3    4   5
```
Your Task:

Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)


Expected Time Complexity: O(N*N).

Expected Auxiliary Space: O(N).

Constraints:

1<=Number of Nodes<=1000

## Approach
1. Iterate over the pre-order traversal array.
2. Find the element in the inorder array and then divide the inorder arry into two arrays.
3. Create the node from the element.
4. Call the function recursively for left part of the array and rigth part of the array.
5. Return the root element.

## Code
```cpp
// Function for finding position
    int getPosition(int in[],int n, int key, int start, int end){
        for(int i = start; i<=end; i++){
            if(in[i] == key) return i;
        }
        
        return -1;
    }
    
    Node* solve(int in[], int pre[], int inStart, int inEnd, int &preIndex, int n){
        // if the preorder array ends or any of the left or right array ends
        if(preIndex >= n || inStart > inEnd){
            return nullptr;
        }
        
        // Storing the element
        int preElement = pre[preIndex++];
        
        // Creating a new node from the element
        Node* root = new Node(preElement);
        
        // Getting the position from the inorder array
        int position = getPosition(in, n, preElement, inStart, inEnd);
        
        // Calling for the left subree with left part of the array
        root->left =  solve(in, pre, inStart, position-1, preIndex, n);
        
        // Calling for the right subree with right part of the array
        root->right =  solve(in, pre, position+1, inEnd, preIndex, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        
        Node* root =  solve(in, pre, 0, n-1, preIndex, n);
        
        return root;
        
    }
```


