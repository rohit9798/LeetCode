Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 

Example 1:


Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
Example 2:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
Example 3:


Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0



class Solution {
public:
    vector<int> gridToVec(vector<vector<int>> &grid)
    {
        vector<int> temp;
        for(int i = 0; i < grid.size(); i++)
        {
            int count = 0;
            for(int j = grid[i].size() - 1; j >= 0; j--)
            {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            temp.push_back(count);
        }
        return temp;
    }
    int minSwaps(vector<vector<int>>& grid) {
        
        vector<int> temp = gridToVec(grid);
        int n = temp.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(temp[i] < n - i - 1)
            {
                int j = i;
                while(j < n && temp[j] < n - i - 1)
                    j++;
                if(j == n)
                    return -1;
                while(j > i)
                {
                    int temp1 = temp[j];
                    temp[j] = temp[j - 1];
                    temp[j - 1] = temp1;
                    j--;
                    result++;
                }
            }
        }
        return result;
    }
};
