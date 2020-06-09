Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]



class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> temp;
        vector<string> result;
        for(int i = 0; i < text.length(); i++)
        {
            string temp1 = "";
            while(i < text.length() && text[i] != ' ')
            {
                temp1 += text[i];
                i++;
            }
            temp.push_back(temp1);
        }
        for(int i = 0; i < temp.size(); i++)
        {
            if(i + 1 < temp.size() && i + 2 < temp.size() && temp[i] == first && temp[i + 1] == second)
                result.push_back(temp[i + 2]);
        }
        return result;
    }
};
