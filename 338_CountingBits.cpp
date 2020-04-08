Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]


class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> result;
        result.push_back(0);
        if(num == 0)
            return result;
        result.push_back(1);
        if(num == 1)
            return result;
        result.push_back(1);
        for(int i = 3; i<= num; i++)
        {
            result.push_back(result[i / 2]* result[2] + result[i % 2]);
        }
        return result;
    }
};
