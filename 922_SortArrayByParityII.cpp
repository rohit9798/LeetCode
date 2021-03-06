Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.



class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        /*vector<int> result(A.size());
        int odd = 1, even = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] & 1)
            {
                result[odd] = A[i];
                odd += 2;
            }
            else
            {
                result[even] = A[i];
                even += 2;
            }
        }
        return result;*/
        int odd = 1, even = 0;
        while(1)
        {
            while(odd < A.size() && A[odd] % 2 == 1)
                odd = odd + 2;
            while(even < A.size() && A[even] % 2 == 0)
                even = even + 2;
            if(odd < A.size() && even < A.size())
            {
                int temp = A[odd];
                A[odd] = A[even];
                A[even] = temp;
            }
            else
                break;
        }
        return A;
    }
};
