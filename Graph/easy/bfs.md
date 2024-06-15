# DFS of Graph
## Quesion 
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?page=1&category=Graph

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web/Other/e0eb5630-5d6c-493a-9b1e-d16d40f10b01_1685086421.png)
```
Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}

Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.
```

Example 2:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web/Other/001e9e35-da68-4024-b1d3-e34944188a1e_1685086422.png)
```
Input:
V = 3, E = 2
adj = {{1,2},{},{}}

Output: 
0 1 2
```
Explanation:<br>
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,<br>
thus bfs will be 0 1 2. 

Your task:<br>
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


Expected Time Complexity: O(V + E)<br>
Expected Auxiliary Space: O(V)

## Approach
Refer to this article on GeeksForGeeks for understanding - https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

1. The Adjacency matrix is given, *create if not!*
2. Create a visited map to keep track of every visited node.
3. Create a queue and push the started node to it.
4. Mark the first node as visited.
5. Unitl queue is empty-
    - pop out the front element of the queue and push it to the answer array.
    - from the array of that node, push each element to the queue and mark it as visited.
6. Return the answer.

### **Note-**<br> 
1. If the adjacency matrix is not given use a map of int -> array and create the matrix.
2. In case of an undirected graph, loop through each vertex and if the vertex is not already visited run BFS for that perticular node.
3. If the output needs to be sorted use a set.

## Code
```cpp
void bfs(vector<int> adj[], unordered_map<int, bool> &visited, int V, int n, vector<int> &ans){
        queue<int> q;
        q.push(n);
        visited[n] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
            
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int, bool> visited;
        bfs(adj, visited, V, 0, ans);
        return ans;
    }
```

