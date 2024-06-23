# Cycle Detection in a directed graph

## Quesion

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Example 1:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700218/Web/Other/9a013355-2510-4ab0-b554-1a2b9f6cb44f_1685086462.png)

```
Output: 1
Explanation: 3 -> 3 is a cycle
```

Example 2:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700218/Web/Other/b1096e14-7c18-47d8-a4e9-8dd42b2e466f_1685086462.png)

```
Output: 0
Explanation: no cycle in the graph
```

Your task:<br>
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)<br>
Expected Auxiliary Space: O(V)

## Approach
### 1 - Using DFS and Visited array Concept

Refer to these resources for better understanding:

- Article - https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
- Video - https://www.youtube.com/watch?v=9twcmtQj4DU

### 2 - Using Kahn's algorithm
We know that the kahn's algorithm gives a valid topological sort, but we know that a valid topological sort can only be determined in a **Directed Acyclic Graph**, if the topological sort is invalid that means there is a *Cycle.*

A valid topological sort always consist the given no. of vertices.

If instead of pushing the vertices into the answer, we simply count the no. of vertices, if it is not equal to the given no. of vertices the cycle exists.

## Code
### Using DFS and Visited Comcept
#### Using Visited and Path Visited Arrays
```cpp
    bool checkCycle(vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> &pathVisited, int V, int n){
        
        visited[n] = pathVisited[n] = true;
        
        for(auto i : adj[n]){
            if(!visited[i]){
                if(checkCycle(adj, visited, pathVisited, V, i)) return true;
            }
            if(visited[i] && pathVisited[i]) return true;
        }
        
        pathVisited[n] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited, pathVisited;
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(checkCycle(adj, visited, pathVisited, V, i)) return true;
            }
        }
        return false;
    }
```

#### Using single visited array
```cpp
    bool checkCycle(vector<int> adj[], unordered_map<int, int> &visited, int V, int n){
        
        visited[n] = 2;
        
        for(auto i : adj[n]){
            if(visited[i] == 0){
                if(checkCycle(adj, visited, V, i)) return true;
            }
            if(visited[i] == 2) return true;
        }
        
        visited[n] = 1;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, int> visited;
        
        for(int i = 0; i<V; i++){
            if(visited[i] == 0){
                if(checkCycle(adj, visited,  V, i)) return true;
            }
        }
        return false;
    }
```

### Using Kahn's algorithm and bfs
```cpp
bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
	    queue<int> q;
	    int count = 0;
	    
	    for(int i = 0; i<V; i++){
	        for(auto j : adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int f = q.front();
	        q.pop();
	        
	        count++;
	        
	        for(auto i : adj[f]){
	            indegree[i]--;
	            if(indegree[i] == 0) q.push(i);
	        }
	    }
	    
	    return !(count == V);
    }
```
