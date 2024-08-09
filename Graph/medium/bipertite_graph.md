# Bipertite Graph

## Quesion

https://www.geeksforgeeks.org/problems/bipartite-graph/1

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

Example 1:

![Eg](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700410/Web/Other/cdb283af-c52d-46df-8646-5017b45b5a13_1685086658.png)

```
Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
```


Example 2:

![Eg](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700410/Web/Other/471d9abf-5d47-48ea-aa35-2dace9f5a2da_1685086659.png)

```
Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 ```

Your Task:<br>
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)<br>
Expected Space Complexity: O(V)

Constraints:<br>
1 ≤ V, E ≤ 10<sup>5</sup>

## Approach

We will use a color array, which will have values as
- -1 : No Color
- 1 : Red
- 0 : Blue

Initially all the values of the color array will be -1.
### Using BFS
1. Take a queue
2. Push the first node in the queue and color it with any color (1/0).
3. Start the bfs traversal as follows:
    - Pop out the front node.
    - Iterate over the adjacency list and if the node is not colored - color it with the opposite color of the front node.
    - If the node has same color as the front node, return false

### Using DFS
1. Color the node.
2. Iterate over the adjacency list of the node.
3. If it is not colored call the dfs for it with opposite color, if it returns false, return false.
4. If it is already colored and the color is equal to the current node return false.

## Code
### Using BFS
```cpp
bool bfs(int start, vector<int> adj[], vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !color[node];
                }
                else if(color[i] == color[node]){
                    return false;
                }
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V);
	    
	    for(int i = 0; i<V; i++) color[i] = -1;
	    
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(!(bfs(i, adj, color))) return false;
	        }
	    }
	    
	    return true;
	}

```

### Using DFS
```cpp
bool dfs(int start, vector<int> adj[], vector<int> &color, int col){
        
        color[start] = col;
        
        for(auto i : adj[start]){
            if(color[i] == -1){
                if(!(dfs(i, adj, color, !col))) return false;
            }
            else if(color[i] == col){
                return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V);
	    
	    for(int i = 0; i<V; i++) color[i] = -1;
	    
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(!(dfs(i, adj, color, 0))) return false;
	        }
	    }
	    
	    return true;
	}

```
