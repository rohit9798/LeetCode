You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        map<char, int> m1, m2;
        for(int i = 0; i < chars.length(); i++)
        {
            m1[chars[i]]++;
        }
        m2 = m1;
        int sum = 0, flag = 0;
        for(int i = 0; i < words.size(); i++)
        {
            flag = 0;
            m1 = m2;
            for(int j = 0; j < words[i].length(); j++)
            {
                if(m1.find(words[i][j]) == m1.end() || m1[words[i][j]] == 0)
                {
                    flag = 1;
                    break;
                }
                else
                    m1[words[i][j]]--;
            }
            if(flag == 0)
                sum = sum + words[i].length();
        }
        return sum;
    }
};
