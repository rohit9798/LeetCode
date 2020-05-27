Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false



class Solution {
public:
    bool dfs(int node, int c, map<int, int> &color, vector<vector<int>> &graph)
    {
        if(color.find(node) != color.end())
            return color[node] == c;
        color[node] = c;
        for(int i = 0; i < graph[node].size(); i++)
            if(!dfs(graph[node][i], c ^ 1, color, graph))
                return false;
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    
        map<int, int> color;
        vector<vector<int>> graph(N);
        for(int i = 0; i < dislikes.size(); i++)
        {
            graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        for(int i = 0; i < N; i++)
        {
            if(color.find(i) == color.end() && !dfs(i, 0, color, graph))
                return false;
        }
        return true;
    }
};
