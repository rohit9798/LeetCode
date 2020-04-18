Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int a = -(mat.size() - 1);
        if(mat[0].size() == 1)
            return mat;
        vector<int> res ;
        for(int i = a; i < (int)mat[0].size(); i++)
        {
            int temp = abs(i);
            for(int j = 0; j < mat.size(); j++)
            {
                if(i < 0 && temp < mat.size())
                    res.push_back(mat[temp][j]);
                else if(i >= 0 && i + j < mat[0].size())
                    res.push_back(mat[j][j + i]);
                temp++;
            }
            sort(res.begin(), res.end());
            temp = abs(i);
            int index = 0; 
            for(int j = 0; j < mat.size(); j++)
            {
                if(i < 0 && temp < mat.size())
                    mat[temp][j] = res[index];
                else if(i >= 0 && i + j < mat[0].size())
                    mat[j][j + i] = res[index];
                temp++;
                index++;
            }
            res.clear();
        }
        return mat;
        
    }
};
