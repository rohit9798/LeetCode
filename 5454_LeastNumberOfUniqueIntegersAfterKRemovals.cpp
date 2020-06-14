Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.



class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int, int> m1;
        multimap<int, int> m2;
        for(int i = 0; i < arr.size(); i++)
        {
            m1[arr[i]]++;
        }
        map<int, int> :: iterator itr = m1.begin();
        while(itr != m1.end())
        {
            m2.insert({itr -> second, itr -> first});
            itr++;
        }
        multimap<int, int> :: iterator itr2 = m2.begin();
        while(k)
        {
            int check = itr2 -> first;
            cout<<check<<" ";
            m2.erase(itr2);
            if(check > 1)
                m2.insert({--check, 1});
            k--;
            itr2 = m2.begin();
        }
        return m2.size();
    }
};
