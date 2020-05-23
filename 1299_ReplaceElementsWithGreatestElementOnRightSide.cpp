Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        vector<int> result(arr.size());
        int maximum = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--)
        {
            result[i] = maximum;
            if(maximum < arr[i])
                maximum = arr[i];
        }
        result[arr.size() - 1] = -1;
        return result;
    }
};
