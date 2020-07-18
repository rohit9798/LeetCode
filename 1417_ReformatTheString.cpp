Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"



class Solution {
public:
    string reformat(string s) {
        
        string result = "";
        string character = "", number = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
                number = number + s[i];
            else
                character += s[i];
        }
        if((character.length() == 0 && number.length() > 1) || (number.length() == 0 && character.length() > 1))
            return result;
        if(abs((int)character.length() - (int)number.length()) > 1)
            return result;
        int i = 0, j = 0;
        if(character.length() >= number.length())
        {
            
            while(j < number.length())
            {
                result += character[i];
                result += number[j];
                i++;
                j++;
            }
            if(i < character.length())
                result += character[i];
        }
        else if(character.length() < number.length())
        {
            while(j < character.length())
            {
                result += number[j];
                result += character[j];
                i++;
                j++;
            }
            if(j < number.length())
                result += number[j];
        }
        return result;
    }
};