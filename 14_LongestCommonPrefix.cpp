Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.



class Solution {
public:
    struct TrieNode
    {
        map<char, TrieNode*> child;
        bool eow;
    };
    TrieNode* root;
    void insert(TrieNode *root, string word)
    {
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(curr ->child.find(word[i]) == curr -> child.end())
            {
                TrieNode *node = new TrieNode();
                node -> eow = false;
                curr -> child[word[i]] = node;
                curr = node;
            }
            else
                curr = curr -> child[word[i]];
        }
        curr -> eow = true;
    }
    bool search(TrieNode* root, string word)
    {
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(curr ->child.find(word[i]) == curr -> child.end())
                return false;
            curr = curr -> child[word[i]];
        }
        return curr -> eow;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        root = new TrieNode();
        string result = "";
        for(int i = 0; i < strs.size(); i++)
        {
            insert(root, strs[i]);
        }
        TrieNode *curr = root;
        while(curr -> child.size() == 1 && curr -> eow == false)
        {
            result = result + curr -> child.begin() -> first;
            curr = curr -> child.begin() -> second;
        }
        return result;
    }
};
