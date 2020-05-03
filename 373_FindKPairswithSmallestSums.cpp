You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> result;
        if(nums1.size() == 0 || nums2.size() == 0)
            return result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int sum = nums1[0] + nums2[0];
        map<pair<int, int>, int> m;
        m[{0, 0}]++;
        pq.push({sum,{0, 0}});
        int count = 0, value;
        while(count < k && pq.size() != 0)
        {
            auto temp = pq.top();
            pq.pop();
            value = temp.first;
            vector<int> temp1;
            
            temp1.push_back(nums1[temp.second.first]);
            temp1.push_back(nums2[temp.second.second]);
            result.push_back(temp1);
            pair<int, int> p1 = {temp.second.first, temp.second.second + 1};
            if(p1.second < nums2.size())
            {    
                if(m[p1] == 0)
                {
                    sum = nums1[p1.first] + nums2[p1.second];
                    pq.push({sum, p1});
                    m[p1]++;
                }
            }
            pair<int, int> p2 = {temp.second.first + 1, temp.second.second};
            if(p2.first < nums1.size())
            {
                if(m[p2] == 0)
                {
                    sum = nums1[p2.first] + nums2[p2.second];
                    pq.push({sum, p2});
                    m[p2]++;
                }
            }
            count++;
        }
        return result;
    }
};
