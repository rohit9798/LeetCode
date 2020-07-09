Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]



class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> result;
        multimap<int, int> m;
        for(int i = 0; i < mat.size(); i++)
        {
            int low = 0, high = mat[i].size() - 1;
            int count = 0;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(mat[i][low] == 0)
                    break;
                if(mat[i][mid] == 1 && mid + 1 > high)
                {
                    count = mid + 1;
                    break;
                }
                if(mat[i][mid] == 1 && mat[i][mid + 1] == 0)
                {
                    count = mid + 1;
                    break;
                }
                else if(mat[i][mid] == 1)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            m.insert({count, i});
        }
        multimap<int, int> :: iterator itr = m.begin();
        while(k > 0 && itr != m.end())
        {
            result.push_back(itr -> second);
            itr++;
            k--;
        }
        return result;
    }
};
