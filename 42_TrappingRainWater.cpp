Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6



class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0)
            return 0;
        int left[height.size()];
        left[0] = height[0];
        for(int i = 1; i < height.size(); i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        int right = height[height.size() - 1];
        int result = 0;
        for(int i = height.size() - 1; i >= 0; i--)
        {
            right = max(height[i], right);
            result += min(left[i], right) - height[i];
        }
        return result;
    }
};
