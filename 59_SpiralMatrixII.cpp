Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int> (n));
        int start_row = 0, start_col = 0, end_row = n - 1, end_col = n - 1;
        int count = 1;
        while(start_row <= end_row && start_col <= end_col)
        {
            for(int i = start_col; i <= end_col; i++)
            {
                matrix[start_row][i] = count++;
            }
            start_row++;
            for(int i = start_row; i <= end_row; i++)
            {
                matrix[i][end_col] = count++;
            }
            end_col--;
            if(end_row >= start_row)
            {
                for(int i = end_col; i >= start_col; i--)
                {
                    matrix[end_row][i] = count++;
                }
                end_row--;
            }
            if(end_col >= start_col)
            {
                for(int i = end_row; i >= start_row; i--)
                {
                    matrix[i][start_col] = count++;
                }
                start_col++;
            }
        }
        return matrix;
    }
};
