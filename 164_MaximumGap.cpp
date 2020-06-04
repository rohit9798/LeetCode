Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.



class Solution {
public:
    class Bucket
    {
        public:
            bool used = false;
            int minval = INT_MAX;
            int maxval = INT_MIN;
    };
    int maximumGap(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() < 2)
            return 0;
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        
        int bucketSize = max(1, (maximum - minimum) / ((int)nums.size() - 1));
        int bucketNumber = (maximum - minimum) / bucketSize + 1;
        vector<Bucket> buckets(bucketNumber);
        for(int i = 0; i < nums.size(); i++)
        {
            int id = (nums[i] - minimum) / bucketSize;
            buckets[id].used = true;
            buckets[id].minval = min(nums[i], buckets[id].minval);
            buckets[id].maxval = max(nums[i], buckets[id].maxval);
        }
        
        int prev = minimum, result = 0;
        for(int i = 0; i < buckets.size(); i++)
        {
            if(!buckets[i].used)
                continue;
            
            result = max(result, buckets[i].minval - prev);
            prev = buckets[i].maxval;
        }
        return result;
    }
};
