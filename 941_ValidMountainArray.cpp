Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]


 

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 




class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        
        if(A.size() < 2)
            return false;
        int flag = 0;
        for(int i = 0; i < A.size() - 1; i++)
        {
            if(flag == 0 && A[i] < A[i + 1])
            {}
            else if(i != 0 && A[i] > A[i + 1])
                flag = 1;
            else
                return false;
        }
        if(flag == 1)
            return true;
        return false;
    }
};
