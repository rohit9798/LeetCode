Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.



class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        map<char, TrieNode*> child;
        bool eow;
    };
    TrieNode *root;
    WordDictionary() {

        root = new TrieNode();
        root -> eow = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(curr -> child.find(word[i]) == curr -> child.end())
            {
                TrieNode  *node = new TrieNode();
                node -> eow = false;
                curr -> child[word[i]] = node;
                curr = node;
            }
            else
                curr = curr -> child[word[i]]; 
        }
        curr -> eow = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchString(TrieNode *curr, string word, int len)
    {
        if(word.size() == len)
            return curr -> eow;
        if(word[len] != '.')
        {
            if(curr -> child.find(word[len]) == curr -> child.end())
                return false;
            return searchString(curr -> child[word[len]], word, len + 1);
        }
        else
        {
            map<char, TrieNode*> :: iterator itr = curr -> child.begin();
            for(; itr != curr -> child.end(); itr++)
            {
                if(searchString(itr -> second, word, len + 1))
                   return true;
            }
        }
        return false;
        
    }
    bool search(string word) {
        
        TrieNode *curr = root;
        return searchString(curr, word, 0);
        
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
