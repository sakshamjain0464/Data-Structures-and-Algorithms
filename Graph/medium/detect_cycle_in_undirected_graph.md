# Cycle Detection in an undirected graph

## Quesion

https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with

Example 1:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/891791f9-1abb-45b1-80f2-7af46d73dcd2_1685086491.png)

```
Input:
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
Output: 1

Explanation:
1->2->3->4->1 is a cycle.
```

Example 2:

![Image](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/d8cbd97e-406e-4f50-a38c-6a58747df876_1685086491.png)

```
Input:
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0

Explanation:
No cycle in the graph.
```

Your task:<br>
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

Expected Time Complexity: O(V + E)<br>
Expected Auxiliary Space: O(V)

## Approach

Refer to these resources for better understanding:

- Article - https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
- Video - https://www.youtube.com/watch?v=BPlrALf1LDU

1. We are using BFS for this solution
2. Iterate over each vertex and if that vertex is not visited call the detectCycle function for that vertex, if the function returns true the there is a cycle.
3. In the detectCycle Function
   1. Create a queue of pair<int, int>, for keeping node and its parent.
   2. Push the pair of source vertex and -1 into the queue._As there is no parent to source node we are pushing -1_.
   3. While queue is not empty, take out the front element and extract the current node and parent from the pair.
   4. Iterate over the adjacency list of the current node, if the node in the adjacency list is not visited, create its pair with the current node and push to queue.
   5. If it is visited and its parent is not equal to the node in the adjacency list return true.
   6. After the while loop return false.

## Code

```cpp
    queue<pair<int, int>> q;
        q.push({n,-1});
        visited[n] = true;

        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();

            int current = front.first;
            int parent = front.second;

            for(auto i : adj[current]){
                if(!visited[i]){
                    q.push({i, current});
                    visited[i] = true;
                }
                else if(i != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;

        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(detect(adj, visited, V, i)) return true;
            }
        }

        return false;
    }
```
