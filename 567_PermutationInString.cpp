Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        map<char, int> mp, ms;
        if(s1.size() == 0 || s2.size() == 0 || s1.size() > s2.size())
            return false;
        for(int i = 0; i < s1.length(); i++)
        {
            mp[s1[i]]++;
            ms[s2[i]]++;
        }
        if(mp == ms)
            return true;
        int k = s1.length();
        for(int i = k; i < s2.length(); i++)
        {
            cout<<s2[i - k]<<" "<<s2[i]<<" ";
            if(ms[s2[i - k]] == 1)
                ms.erase(s2[i - k]);
            else
                ms[s2[i - k]]--;
            ms[s2[i]]++;
            if(mp == ms)
                return true;
        }
        return false;
    }
};
