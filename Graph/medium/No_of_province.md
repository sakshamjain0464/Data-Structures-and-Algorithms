# No. of Provinces

## Question

https://www.geeksforgeeks.org/problems/number-of-provinces/1

Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706298/Web/Other/763b704c-74af-4d7c-8457-a1b8fe00a077_1685087210.png)


```
Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2

Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
```
![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/706298/Web/Other/f1fc32d4-70bb-429d-be95-a1485e4ae057_1685087210.png)


```
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

```

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V ≤ 500



## Approach

Idea - As we are given that each province is a component of a disconnected graph, so the question asks to find the no. of components in the graph.<br>
To find the no. of components in a graph we can use the traversal and each time we run a traversal on a component we just count that.

1. Create an adjacency list from the matrix.

2. Initialize the answer variable to 0.

3. Use a loop to iterate all the vertices if it is not visited call the DFS traversal

*Note - The same can be done using BFS also*

## Code

```cpp
void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int node){
        visited[node] = true;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
        
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        
        unordered_map<int, vector<int>> l;
        
        for(int i  = 0; i < V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j] == 1 && i!=j){
                    l[i].push_back(j);
                    l[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(V);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                ans++;
                dfs(l, visited, i);
            }
        }
        
        return ans;
    }
```