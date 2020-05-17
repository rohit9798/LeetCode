Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".



class Solution {
public:
    vector<int> findAnagrams(string p, string s) {
        
        vector<int> result;
        int size = s.size();
        map<char, int> mp, ms;
        for(int i = 0; i < s.size(); i++)
            ms[s[i]]++;
        for(int i = 0; i < s.size(); i++)
        {
            mp[p[i]]++;
        }
        if(mp == ms)
            result.push_back(0);
        for(int i = size; i < p.size(); i++)
        {
            if(mp[p[i - size]] == 1)
                mp.erase(p[i - size]);
            else
                mp[p[i - size]]--;
            mp[p[i]]++;
            if(mp == ms)
                result.push_back(i - size + 1);
        }
        return result;
    }
};
