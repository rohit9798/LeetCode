Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
            nums1 = nums2;
        

        int i = 0, j = 0, ptr = 0;
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
                i++;
                m++;
                j++;
            }
        }
        while(j < n)
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            i++;
            j++;
            
        }
        for(int i = 0; i < n; i++)
            nums1.pop_back();
    }
};
