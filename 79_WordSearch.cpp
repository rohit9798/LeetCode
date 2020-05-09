Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3



class Solution {
public:
    
    bool search(vector<vector<char>>& board, string &word, int row, int col, int index)
    {
        char temp;
        if(index == word.size())
            return true;
        if(row < 0 || row >= board.size())
            return false;
        if(col < 0 || col >= board[0].size())
            return false;
        if(board[row][col] == '.')
            return false;
        if(board[row][col] == word[index])
        {
            index = index + 1;
            temp = board[row][col];
            board[row][col] = '.';
        }
        else
            return false;
        if(search(board, word, row, col + 1, index) || search(board, word, row + 1, col, index) || search(board, word, row, col - 1, index) || search(board, word, row - 1, col, index))
            return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(search(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
