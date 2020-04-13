Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int index = 0;
        while(index < A.size() - 1)
        {
            if(A[index + 1] > A[index])
                index++;
            else
            {
                int i = index + 1;
                while(i < A.size())
                {
                    if(A[index] < A[i])
                    {
                        index = i;
                        break;
                    }
                    i++;
                }
                if(i == A.size())
                    return index;
            }
        }
        return index;
        
    }
};
