Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1



class Solution {
public:
    void swap(int *p, int *q)
    {
        int temp = *p;
        *p = *q;
        *q = temp;
    }
    void reverse(vector<int> &A, int start, int end)
    {
        while(start < end)
        {
            swap(&A[start++], &A[end--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        
        int position = -1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i + 1] > nums[i])
            {
                position = i;
                break;
            }
        }
        if(position == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int min = INT_MAX, close = 0;
        for(int i = position + 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[position] && nums[i] - nums[position] <= min)
            {
                min = nums[i] - nums[position];
                close = i;
            }
        }
        swap(&nums[position], &nums[close]);
        reverse(nums, position + 1, nums.size() - 1);
    }
};
