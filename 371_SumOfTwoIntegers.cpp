Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1



class Solution {
public:
    int getSum(int a, int b) {
        
        int result = 0;
        bool c = 0;
        for(int i = 0; i < 32; i++)
        {
            bool carry = ((a & 1) & (b & 1)) | ((b & 1) & (c)) | ((a & 1) & (c));
            bool sum = (a & 1) ^ (b & 1) ^ c;
            result = result | (sum << i);
            a = a >> 1;
            b = b >> 1;
            c = carry;
        }
        return result;
    }
};
