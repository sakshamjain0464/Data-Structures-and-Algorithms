# DFS of Graph
## Quesion 
https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/

You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

![Image](https://media.geeksforgeeks.org/img-practice/graph-1659528381.png)
```
Example 1:

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.
```

![Image](https://media.geeksforgeeks.org/img-practice/graph(1)-1659528893.png)
```
Example 2:

Input: V = 4, adj = [[1,3], [2,0], [1], [0]]

Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 
```
Your task:<br>
You don't need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Expected Time Complexity: O(V + E)<br>
Expected Auxiliary Space: O(V)

## Approach
To study breadth first search in detail refer to - https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

1. Create an answer vector and a visited map to track the visited node.
2. Call the DFS function for the first node.
3. In DFS function recieve a node, then-
    - Mark it as visited.
    - Get its edges from the adjacency matrix
    - Loop through all edges and call DFS function for each edge


## Code
```cpp
oid bfs(int n, vector<int> adj[], vector<int> &ans, unordered_map<int, bool> &visited){
        visited[n] = true;
        ans.push_back(n);
        
        for(auto i : adj[n]){
            if(!visited[i]){
                bfs(i, adj, ans, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int, bool> visited;
        bfs(0, adj, ans, visited);
        return ans;
    }
```