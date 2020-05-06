The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.




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
    void queen(vector<vector<string>> &result, vector<string> &temp, int row, int n)
    {
        if(row == n)
        {
            result.push_back(temp);
            return;
        }  
        for(int i = 0; i < n; i++)
        {
            if(validate(temp, row, i, n))
            {
                temp[row][i] = 'Q';
                queen(result, temp, row + 1, n);
                temp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        int row = 0;
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        queen(result,temp, row, n);
        return result;
    }
};
