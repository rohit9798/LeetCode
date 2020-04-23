Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
             
             
             
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0)
            return 0;
        int len = 0, max_len = 0;
        map<char, int> m;
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) != m.end())
            {
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            len = max(len, i - start + 1);
        }
        return len;
    }
};
