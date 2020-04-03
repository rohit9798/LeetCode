Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.



class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int no_of_rows = grid.size();
        int no_of_columns = grid[0].size();
        int count = 0, flag = 0, j = 0, i = 0;
        for(i = 0; i < no_of_rows; i++)
        {
            for(j = 0; j < no_of_columns; j++)
            {
                if(grid[i][j] < 0)
                {
                    count = count + ((no_of_rows - i) * (no_of_columns - j));
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                no_of_columns = j ;
                flag = 0;
            }
        }
        return count;
        
        /*
        [4, 3, 2, -1]
        [3, 2, 1, -1]
        [1, 1,-1, -2]
        [-1,-1,-2,-3]
        */
    }
};
