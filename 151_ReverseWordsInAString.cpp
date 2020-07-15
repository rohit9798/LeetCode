Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.



class Solution {
public:
    string reverseWords(string s) {
        
        string result = "", word = "";
        vector<string> vec;
        for(int i = 0; i < s.length();)
        {
            word = "";
            while(i < s.length() && s[i] == ' ')
                i++;
            while(i < s.length() && s[i] != ' ')
            {
                word = word + s[i];
                i++;
            }
            if(word.length() > 0)
                vec.push_back(word);
        }
        for(int i = vec.size() - 1; i >= 0; i--)
            result += vec[i] + " ";
        if(result.length() > 0)
            result.pop_back();
        return result;
    }
};
