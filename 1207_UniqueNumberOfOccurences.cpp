Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> result;
        sort(arr.begin(), arr.end());
        int i = 0, count = 0;
        while(i < arr.size())
        {
            count = 0;
            while(i < arr.size() - 1 && arr[i] == arr[i + 1])
            {
                i++;
                count++;
            }
            result.push_back(count);
            i++;
        }
        sort(result.begin(), result.end());
        i = 0;
        while(i < result.size() - 1)
        {
            if(result[i] == result[i + 1])
                return false;
            i++;
        }
        return true;
    }
};
