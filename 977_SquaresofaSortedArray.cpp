Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]



class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int i = 0, index = A.size() - 1;
        int j = A.size() - 1;
        vector<int> result(A.size());
        while(i <= j)
        {
            if( abs(A[i]) > abs(A[j]))
            {
                A.insert(A.begin() + j + 1, A[i]);
                result[index--] = A[i] * A[i];
                i++;
            }
            else
            {
                result[index--] = A[j] * A[j];
                j--;
            }
        }
        return result;
    }
};
