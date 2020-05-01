In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]



class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        
        int count = 0, sum = 0;
        map<int, int> m;
        for(int i = 0; i < A.size(); i++)
        {
            sum = sum + A[i];
            if(sum == S)
                count++;
            if(m.find(sum - S) != m.end())
                count += m[sum - S];
            m[sum]++;
        }
        return count;
    }
};
