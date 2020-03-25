Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000


class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> result;
        int index1 = n / 2;
        index1 = -index1;
        if(n % 2 == 0)
        {
            while(n)
            {
                if(index1 == 0)
                {
                    index1++;
                    continue;
                }
                result.push_back(index1);
                index1++;
                n--;
            }
        }
        else
        {
            while(n)
            {
                result.push_back(index1);
                index1++;
                n--;
            }
        }
        return result;
    }
};
