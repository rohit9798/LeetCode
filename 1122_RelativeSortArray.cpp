Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> result;
        map<int, int> m;
        for(int i = 0; i < arr1.size(); i++)
        {
            m[arr1[i]]++;
        }
        for(int i = 0; i < arr2.size(); i++)
        {
            int count = m[arr2[i]];
            while(count > 0)
            {
                result.push_back(arr2[i]);
                count--;
            }
            m.erase(arr2[i]);
        }
        
        while(m.size() > 0)
        {
            int count = m.begin() -> second;
            while(count > 0)
            {
                result.push_back(m.begin() -> first);
                count--;
            }
            m.erase(m.begin() -> first);
        }
        return result;
    }
};
