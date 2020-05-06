The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]



class Solution {
public:
    bool validate(vector<string> &temp, int row, int col, int n)
    {
        for(int i = row - 1; i >= 0; i--)
        {
            if(temp[i][col] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(temp[i][j] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if(temp[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void queen(vector<string> &temp, int &count, int row, int n)
    {
        if(row == n)
        {
            count++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(validate(temp, row, i, n))
            {
                temp[row][i] = 'Q';
                queen(temp, count, row + 1, n);
                temp[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        int result = 0, row = 0;
        vector<string> temp(n ,string(n, '.'));
        queen(temp, result, row, n);
        return result;
    }
};
