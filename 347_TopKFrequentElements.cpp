Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        map<int, int, greater<int>> m1;
        multimap<int, int, greater<int>> m2;
        for(int i = 0; i < nums.size(); i++)
            m1[nums[i]]++;
        map<int, int> :: iterator itr = m1.begin();
        while(itr != m1.end())
        {
            m2.insert({itr -> second, itr -> first});
            itr++;
        }
        multimap<int, int, greater<int>> :: iterator itr2 = m2.begin();
        for(int i = 0; i < k; i++)
        {
            result.push_back(itr2 -> second);
            itr2++;
        }
        return result;
    }
};
