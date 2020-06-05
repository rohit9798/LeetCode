Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]



class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        vector<string> result;
        map<char, int> m;
        string temp = "";
        for(int i = 0; i < A[0].size(); i++)
            m[A[0][i]]++;
        for(int i = 1; i < A.size(); i++)
        {
            temp = "";
            for(int j = 0; j < A[i].size(); j++)
            {
                if(m.find(A[i][j]) != m.end() && m[A[i][j]] != 0)
                {
                    temp = temp + A[i][j];
                    m[A[i][j]]--;
                }
            }
            m.clear();
            for(int j = 0; j < temp.length(); j++)
                m[temp[j]]++;
        }
        for(int i = 0; i < temp.length(); i++)
        {
            string s(1, temp[i]);
            result.push_back(s);
        }
        return result;
    }
};
