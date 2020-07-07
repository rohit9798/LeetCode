In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int result = 0;
        queue<pair<int, int>> q;
        pair<int, int> del = {-1, -1};
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push(del);
        cout<<q.size();
        while(!q.empty())
        {
            if(q.front() == del)
            {
                result++;
                if(q.size() > 1)
                    q.push(del);
                q.pop();
            }
            else
            {
                auto temp = q.front();
                    if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == 1)
                    {
                        grid[temp.first - 1][temp.second] = 2;
                        q.push({temp.first - 1, temp.second});
                    }
                    if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == 1)
                    {
                        grid[temp.first][temp.second - 1] = 2;
                        q.push({temp.first, temp.second - 1});
                    }
                    if(temp.first < grid.size() - 1 && grid[temp.first + 1][temp.second] == 1)
                    {
                        grid[temp.first + 1][temp.second] = 2;
                        q.push({temp.first + 1, temp.second});
                    }
                    if(temp.second < grid[temp.first].size() - 1 && grid[temp.first][temp.second + 1] == 1)
                    {
                        grid[temp.first][temp.second + 1] = 2;
                        q.push({temp.first, temp.second + 1});
                    }
                q.pop();
            }
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    return -1;
                
            }
        }
        return result - 1;
    }
};
