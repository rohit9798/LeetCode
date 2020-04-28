Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]



class Solution {
public:
    
    int LBinarySearch(vector<int> &A, int low, int high, int &key)
    {
        if(low <= high)
        {
            int mid = (low + high) / 2;  
            if(A[mid] == key)
            {
                if(mid == low)
                    return low;
                else if(A[mid - 1] != A[mid])
                    return mid;
            }
            if(A[mid] < key)
                return LBinarySearch(A, mid + 1, high, key);
            else
                return LBinarySearch(A, low, mid - 1, key);
        }
        return -1;
    }
    int RBinarySearch(vector<int> &A, int low, int high, int &key)
    {
        if(low <= high)
        {
            int mid = (low + high) / 2;  
            if(A[mid] == key)
            {
                if(mid == high)
                    return high;
                else if(A[mid + 1] != A[mid])
                    return mid;
            }
            if(A[mid] > key)
                return RBinarySearch(A, low, mid - 1, key);
            else
                return RBinarySearch(A, mid + 1, high, key);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result;
        int left = LBinarySearch(nums, 0, nums.size() - 1, target);
        int right = RBinarySearch(nums, 0, nums.size() - 1, target);
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};
