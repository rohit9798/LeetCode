We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        multimap<int, int, greater<int>> m;
        for(int i = 0; i < stones.size(); i++)
        {
            m.insert(make_pair(stones[i], i));
        }
        multimap<int,int, greater<int>> :: iterator itr = m.begin(), jtr;
        while(1)
        {
            itr = m.begin();
            jtr = m.begin();
            jtr++;
            if(jtr == m.end())
                break;
            int x = itr -> first;
            int y = jtr -> first;
            m.erase(itr);
            m.erase(jtr);
            m.insert(make_pair(x - y, 1));
        }
        return itr -> first;
    }
};
