Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        if(matrix.size() == 0)
            return result;
        int row = matrix.size() , col = matrix[0].size();
        int start_row = 0, start_col = 0;
        
        while(start_row < row && start_col < col)
        {
            for(int i = start_col; i < col; i++)
            {
                result.push_back(matrix[start_row][i]);
                cout<<matrix[start_row][i];
            }
            start_row++;
            for(int i = start_row; i < row; i++)
            {
                result.push_back(matrix[i][col - 1]);
                cout<<"Hello "<<matrix[i][col - 1];
            }
            col--;
            if(row > start_row)
            {
                for(int i = col - 1; i >= start_col; i--)
                {
                    result.push_back(matrix[row - 1][i]);
                    cout<<"Hi "<<matrix[row - 1][i];
                }
                row--;
            }
            if(col > start_col)
            {
                for(int i = row - 1; i >= start_row; i--)
                {
                    result.push_back(matrix[i][start_col]);
                    cout<<"Bye "<<matrix[i][start_col];
                }
                start_col++;
            }
        }
        return result;
        
    }
};
