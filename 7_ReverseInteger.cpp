Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



class Solution {
public:
    int reverse(int x) {
        
        long result = 0;
        long x1 = x;
        int flag = 0;
        if(x < 0)
        {
            flag = 1;
            x1 = -(long)x;
        }
        while(x1 != 0)
        {
            result = result * 10 + x1 % 10;
            if(result > INT_MAX)
                return 0;
            x1 = x1/10;
        }
        if(flag == 1)
            return -result;
        return result;
    }
};
