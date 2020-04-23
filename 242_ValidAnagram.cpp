Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.



class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int hash[26] = {0};
        if(s.length() != t.length())
            return false;
        for(int i = 0; i < s.length(); i++)
            hash[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++)
            if(hash[t[i] - 'a'] > 0)
                hash[t[i] - 'a']--;
            else
                return false;
        return true;
        
    }
};
