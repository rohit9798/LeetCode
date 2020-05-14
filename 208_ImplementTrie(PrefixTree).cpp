mplement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.




class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        map<char, TrieNode*> child;
        bool eow;
    };
    TrieNode *root;
    Trie() {
        
        root = new TrieNode();
        root -> eow = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(curr -> child.find(word[i]) == curr -> child.end())
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(curr -> child.find(word[i]) == curr -> child.end())
                return false;
            curr = curr -> child[word[i]];
        }
        return curr -> eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode *curr = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(curr -> child.find(prefix[i]) == curr -> child.end())
                return false;
            curr = curr -> child[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
