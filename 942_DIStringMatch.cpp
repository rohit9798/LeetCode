Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]


class Solution {
public:
    vector<int> diStringMatch(string S) {
     
        int minimum = 0;
        int maximum = S.length();
        vector<int> result;
        if(S[0] == 'I')
            result.push_back(minimum++);
        else
            result.push_back(maximum--);
        for(int i = 1; i < S.length(); i++)
        {
            if(S[i] == 'I')
                result.push_back(minimum++);
            else
                result.push_back(maximum--);
        }
        if(S[S.length() - 1] == 'I')
            result.push_back(minimum++);
        else
            result.push_back(maximum--);
        return result;
    }
};
