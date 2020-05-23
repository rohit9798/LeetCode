Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low = 0;
        int high = arr.size() - k;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else
                high = mid;
        }
        vector<int> result(arr.begin() + low, arr.begin() + low + k);
        return result;
        
    }
};
