# Topological Sort

## Question

https://www.geeksforgeeks.org/problems/topological-sort/1

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with V vertices and E edges, your task is to find any valid topological sorting of the graph.

In a topological sort, for every directed edge u -> v, u must come before v in the ordering.

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/24aa5d54-bc1f-489c-bd2d-ad02ddccdf31_1684492511.png)

```
Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
```

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/c35bb1d1-130c-49aa-a17e-118181d7bdcd_1684492512.png)

```
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
```

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).<br>
Expected Auxiliary Space: O(V).

Constraints: <br>
2 ≤ V ≤ 104
1 ≤ E ≤ (N\*(N-1))/2

## Approach

Read more about topological sort - https://www.geeksforgeeks.org/topological-sorting/

### Using DFS

1. Use normal DFS algorithm.
2. After visiting a node just push that node to stack.
3. Pop out all elements of the stack and push them to answer array

### Using Kahn's Algorithm

1. Create an indegree array.
2. Initialize the indegree array with the no. of edges connected to each vertex.
3. Iterate the indegree array, if indegree of any node is 0, push it to queue.
4. While queue is not empty:
   1. Take out the front element, push it to answer
   2. Iterate over its neighbours and decreament their indegree by 1.
   3. If indegree of any neighbour becomes 0, push it to queue.
5. Return the answer array.

## Code

### Using DFS

```cpp
void getsort(vector<int> adj[], int n, stack<int> &s, unordered_map<int, bool> &v){
	    v[n] = true;

	    for(auto i : adj[n]){
	        if(!v[i]) getsort(adj, i, s, v);

	    }

	    s.push(n);
	}
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    unordered_map<int, bool> v;
	    stack<int> s;
	    vector<int> ans;

	    for(int i = 0; i<V; i++){
	        if(!v[i]) getsort(adj, 0, s, v);
	    }

	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }

	    return ans;
	}
```

### Using Kahn's algorithm

```cpp
vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> ans;

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

	        ans.push_back(f);

	        for(auto i : adj[f]){
	            indegree[i]--;
	            if(indegree[i] == 0) q.push(i);
	        }

	    }

	    return ans;
```
