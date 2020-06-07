Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []



class Solution {
public:
    bool static comparator(string s1, string s2)
    {
        return s1.size() < s2.size();
    }
    vector<string> stringMatching(vector<string>& words) {
     
        sort(words.begin(), words.end(), comparator);
        vector<string> result;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(words[j].find(words[i]) != -1)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
