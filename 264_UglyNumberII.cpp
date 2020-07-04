Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.



class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n == 1)
            return 1;
        int ugly[n];
        int n1 = 0, n2 = 0, n3 = 0;
        ugly[0] = 1;
        int temp = 0;
        for(int i = 1; i < n; i++)
        {
            temp = min(2 * ugly[n1], min(3 * ugly[n2], 5 * ugly[n3]));
            ugly[i] = temp;
            if(temp == 2 * ugly[n1])
                n1++;
            if(temp == 3 * ugly[n2])
                n2++;
            if(temp == 5 * ugly[n3])
                n3++;
        }
        return ugly[n - 1];
    }
};
