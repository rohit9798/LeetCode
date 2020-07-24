Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.



class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<vector<int>> &result, vector<int> &temp, int start, int end)
    {
        temp.push_back(start);
        visited[start] = true;
        if(start == end)
        {
            result.push_back(temp);
        }
        else
        {
            for(int i = 0; i < graph[start].size(); i++)
            {
                if(!visited[graph[start][i]])
                {
                    dfs(graph, visited, result, temp, graph[start][i], end);
                }
            }
        }
        visited[start] = false;
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;
        vector<bool> visited(graph.size(), false);
        vector<int> temp;
        dfs(graph, visited, result, temp, 0, graph.size() - 1);
        return result;
    }
};
