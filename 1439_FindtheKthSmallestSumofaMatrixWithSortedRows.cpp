You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

 

Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
Example 2:

Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17
Example 3:

Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
Example 4:

Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
 

Constraints:

m == mat.length
n == mat.length[i]
1 <= m, n <= 40
1 <= k <= min(200, n ^ m)
1 <= mat[i][j] <= 5000
mat[i] is a non decreasing array.



class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int rows = mat.size();
        int columns = mat[0].size();
        int sum = 0;
        map<vector<int>, int> m;
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        vector<int> temp;
        for(int i = 0; i < rows; i++)
        {
            temp.push_back(0);
            sum = sum + mat[i][0];
        }
        pq.push({sum, temp});
        m[temp]++;
        int count = 0;
        int result, temp_sum;
        while(count < k)
        {
            auto temp1 = pq.top();
            pq.pop();
            result = temp1.first;
            sum = temp1.first;
            vector<int> temp_vector = temp1.second;
            for(int i = temp1.second.size() - 1; i >= 0; i--)
            {
                temp_vector = temp1.second;
                temp_vector[i] = temp1.second[i] + 1;
                if(temp_vector[i] == mat[i].size())
                    continue;
                temp_sum = sum - mat[i][temp1.second[i]];
                temp_sum = temp_sum + mat[i][temp_vector[i]];
                cout<<temp_sum<<" ";
                if(m[temp_vector] == 0)
                {
                    pq.push({temp_sum,temp_vector});
                    m[temp_vector]++;
                }
            }
            count++;
        }
        return result;
    }
};
