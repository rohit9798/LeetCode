Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3



class NumArray {
public:
    int *sum;
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1];
        sum[0] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};
