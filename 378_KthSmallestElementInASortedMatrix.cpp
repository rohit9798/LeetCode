Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int start = matrix[0][0];
        int end = matrix[n - 1][m - 1];
        int mid;
        while(start < end)
        {
            mid = (start + end) / 2;
            int num = 0;
            for(int i = 0; i < n; i++)
            {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); 
                num = num + pos;
            }
            if(num < k)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};
