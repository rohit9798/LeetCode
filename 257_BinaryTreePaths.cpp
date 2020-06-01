Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void path(TreeNode* root, vector<string> &result, string temp)
    {
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL)
        {
            temp = temp + to_string(root -> val);
            result.push_back(temp);
            return;
        }
        temp = temp + to_string(root -> val) + "->";
        path(root -> left, result, temp);
        path(root -> right, result, temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
            
        vector<string> result;
        string temp = "";
        if(root == NULL)
            return result;
        path(root, result, temp);
        return result;
    }
};
