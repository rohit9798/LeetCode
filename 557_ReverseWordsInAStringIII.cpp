Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.




class Solution {
public:
    string reverseWords(string s) {
    
        string temp = "", result = "";
        if(s.size() == 0)
            return result;
        for(int i = 0; i < s.length(); i++)
        {
            temp = "";
            while(i < s.length() && s[i] != ' ')
            {
                temp = temp + s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            result = result + temp + " ";
        }
        result.pop_back();
        return result;
    }
};
