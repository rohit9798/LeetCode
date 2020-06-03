There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.



class Solution {
public:
    bool static comparator(vector<int> &v1, vector<int> &v2)
    {
        return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size() / 2;
        int sum = 0;
        sort(costs.begin(), costs.end(), comparator);
        int countA = 0, countB = 0; 
        for(int i = 0; i < costs.size(); i++)
        {
            if(countA < n && countB < n)
            {
                if(costs[i][0] < costs[i][1])
                    countA++;
                else
                    countB++;
                sum = sum + min(costs[i][0], costs[i][1]);
            }
            else if(countA < n)
            {
                countA++;
                sum = sum + costs[i][0];
            }
            else
            {
                sum = sum + costs[i][1];
                countB++;
            }
        }
        return sum;
    }
};
//[[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
//-511, 45, 108, 251, 394, 722 
