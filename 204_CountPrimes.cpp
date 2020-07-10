Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


class Solution {
public:
    int countPrimes(int n) {
       
        if(n < 3)
            return 0;
        int count = 0;
        vector<bool> notprime(n, false);
        notprime[0] = true;
        notprime[1] = true;
        notprime[2] = false;
        for(int i = 2; i < n; i++)
        {
            if(notprime[i] == false)
            {
                count++;
                for(int j = 2; j * i < n; j++)
                    notprime[i * j] = true;
            }
        }
        return count;
    }
};
