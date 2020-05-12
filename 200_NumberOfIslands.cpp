Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3



class Solution {
public:
    int find(int x, vector<int> &parent)
    {
        while(x != parent[x])
            x = parent[x];
        return x;
    }
    void Union(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int r = find(x, parent);
        int s = find(y, parent);
        if(r == s)
            return;
        if(rank[r] >= rank[s])
        {
            if(rank[r] == rank[s])
                rank[r] = rank[r] + 1;
            parent[s] = r;
        }
        else
            parent[r] = s;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        int size = grid[0].size();
        vector<int> parent(grid.size() * size);
        vector<int> rank(grid.size() * size);
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < size; j++)
            {
                parent[i * size + j] = i * size + j;
                rank[i * size + j] = 0;
            }
        }
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    if(i - 1 >= 0 && grid[i - 1][j] == '1')
                        Union(i * size + j, (i - 1) * size + j, parent, rank);
                    if(j - 1 >= 0 && grid[i][j - 1] == '1')
                        Union(i * size + j, i * size + j - 1, parent, rank);
                }
            }
        }
        map<int, int> m;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(grid[i][j] == '1')
                    m[find(i * size + j, parent)]++;
            }
        }
        return m.size();
    }
};
