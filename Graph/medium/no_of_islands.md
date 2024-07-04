# Find the number of islands

## Question

https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

```
Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
```

```
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
```

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)<br>
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500


## Approach

Idea - We can consider the given matrix as a graph and the elements which are given 1 as its nodes. We will not create adjacency list because, if we look closely we can find that the consecutive elements of the current node(elements marked as 1) are connected if they are also marked as 1;

```
Eg - 
0 1
1 0
1 1
1 0

The graph will be :
  1
 /
1
|
1-1
|
1
```


```
Eg:
0 1 1 1 0 0 0
0 0 1 1 0 1 0 

The graph will be:
    1 - 1 - 1
      \ | \ |
        1   1   1
```


We can easily take the elements as nodes using their indices. So, the problem begins same as find the no. of disconnected components in a given graph of same as  - [this problem](./No_of_province.md)

1. We will create a booleam matrix of same dimensions to mark the nodes as visited.

2. We will iterate to each element and if it is '1' and not already visited, we will call bfs for that node, by using its indices.

3. In BFS:
    1. We create a queue of pair (To store both row and column index).

    2. We will push the current node to queue and mark it as visited.

    3. We will start the BFS traversal, in this
        1. We pop out the front element.
        2. Extract the **i** and **j** index of the front node.
        3. Check for its neighbours, if they are '1' and not visited push them to queue and mark them as visited.

4. Increment our counter
5. Return the ans.

### How to check the neighbours:
![image](https://www.baeldung.com/wp-content/uploads/sites/4/2022/10/square_neighbors.jpg)

In the above image we can see that all the rows are running from ```-1 to 1```

Hence we can use a nesed loop for traversing
```
for(x = -1 to +1){
    for(y = -1 to +1){
        new_i = i+x
        new_j = j+y
    }
}
```

if the nww 'i' and new 'j' are in boundaries or ```0 <= new_i <= n ``` and ```0 <= new_j <= m ``` they will be valid elements

**Note** -  We can also write the 8 cases manually by referring to above diagram

*Note - The same can be done using DFS also*

## Code

```cpp
void bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int &ans){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        
        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            
            int i = front.first;
            int j = front.second;
            
            for(int x = -1; x<=1; x++){
                for(int y = -1; y<=1; y++){
                    if(x+i < grid.size() && y+j < grid[0].size() && x+i >= 0 && y+j >= 0 && !visited[x+i][y+j] && grid[i+x][y+j] == '1'){
                        q.push({x+i,y+j});
                        visited[x+i][y+j] = true;
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    bfs(i, j, visited, grid, ans);
                }
            }
        }
        
        return ans;
    }
```