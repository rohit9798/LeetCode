Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Follow up:

Recursive solution is trivial, could you do it iteratively?

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]




/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorderTraversal(Node* root, vector<int> &result)
    {
        if(root != NULL)
        {
            for(int i = 0; i < (root -> children).size(); i++)
            {
                result.push_back(root -> children[i] -> val);
                preorderTraversal(root -> children[i], result);
            }
        }
    }
    vector<int> preorder(Node* root) {
        
        vector<int> result;
        if(root == NULL)
            return result;
        result.push_back(root -> val);
        preorderTraversal(root, result);
        return result;
    }
};