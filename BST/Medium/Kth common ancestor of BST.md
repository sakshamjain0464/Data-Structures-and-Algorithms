# Kth Common ancestor of BST

## Question
Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a BST, and x != y.

Example 1:

Input: 

Input tree

![Input Tree](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861885/Web/Other/blobid0_1712119495.png)

k = 2, x = 40, y = 60 

Output:
30

Explanation:
Their 2nd common ancestor is 30.

Example 2:

Input: 

Input tree

![Input Tree](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861885/Web/Other/blobid0_1712119495.png)

k = 2, x = 40, y = 60

Output:
-1

Explanation:

LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.

Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
Expected Time Complexity: O(Height of the Tree)

Expected Space Complexity: O(Height of the Tree)
 
Your Task :
1 <= n, k <= 105

1 <= node->data, x, y <= 109

## Approach
1. Find the lowest common ancestor of the BST tree.
2. Store the path from the root to the LCA in an array.
3. Iterate the array to find the Kth element from reverse.

## Code
```cpp
void findLCA(Node* root, int &x, int&y){
        if(root == nullptr){
            return;
        }
        
        if(root->data >= x && root->data <= y || root->data <= x && root->data >= y){
            LCA = root;
        }
        
        if(root->data < x && root->data < y){
            findLCA(root->right, x, y);
        }
        
        if(root->data > x && root->data > y){
            findLCA(root->left, x ,y);
        }
    }
    
    void findAncestors(Node* root, vector<int> &anc ){
        if(root == nullptr){
            return;
        }
        
        anc.push_back(root->data);
        
        if(root == LCA) return;
        
        if(root->data < LCA->data){
            findAncestors(root->right, anc);
        }
        
        if(root->data > LCA->data){
            findAncestors(root->left, anc);
        }
        
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        findLCA(root,x, y);
        
        if(LCA == nullptr){
            return -1;
        }
        
        vector<int> ancestors;
        
        findAncestors(root, ancestors);
        
        if(ancestors.size() == 0 || ancestors.size() < k){
            return -1;
        }
        
        if(k == 1){
            return LCA->data;
        }
        
        return ancestors[ancestors.size()-k];
    }
```

## Edge Cases!
1. If K is 1, then return the LCA, because LCA is the first ancestor.
2. If K > no. of ancestors then return -1.