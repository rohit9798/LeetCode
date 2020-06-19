Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6



class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int window = arr.size() / 4;
        for(int i = 0; i < arr.size() - window; i++)
        {
            if(arr[i] == arr[i + window])
                return arr[i];
        }
        return -1;
    }
};
