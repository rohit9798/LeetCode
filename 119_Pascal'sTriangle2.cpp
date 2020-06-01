Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> prev;
        vector<int> next;
        prev.push_back(1);
        if(rowIndex == 0)
            return prev;
        prev.push_back(1);
        for(int i = 0; i < rowIndex - 1; i++)
        {
            next.clear();
            next.push_back(1);
            for(int j = 0; j < prev.size() - 1; j++)
            {
                next.push_back(prev[j] + prev[j + 1]);
            }
            next.push_back(1);
            prev = next;
        }
        return prev;
    }
};
