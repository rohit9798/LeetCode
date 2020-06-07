Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int minimum = INT_MAX;
        map<char, int> m;
        for(int i = 0; i < text.length(); i++)
        {
            m[text[i]]++;
        }
        minimum = min(m['b'], min(m['a'], min(m['l'] / 2, min(m['o'] / 2, m['n']))));
        return minimum;
    }
};
