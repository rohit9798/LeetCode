Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.



class Solution {
public:
    
    
    int quickSelect(vector<int> &nums, int low, int high, int k)
    {
        int i = low, pivot = high;
        for(int j = low; j < high; j++)
        {
            if(nums[j] <= nums[pivot])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i = i + 1;
            }
        }
        int temp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = temp;
        return i;
    }
    int quickSort(vector<int> &nums, int low, int high, int k)
    {
        if(low <= high)
        {
            int pivot = quickSelect(nums, low, high, k);
            if(pivot == k)
                return nums[k];  
            else if(pivot > k)
                return quickSort(nums, low, pivot - 1, k);
            else 
                return quickSort(nums, pivot + 1, high, k);
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        random_shuffle(nums.begin(), nums.end());
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return nums[k - 1];
        return quickSort(nums, 0, nums.size() - 1, nums.size() - k);    
        
    }
};
