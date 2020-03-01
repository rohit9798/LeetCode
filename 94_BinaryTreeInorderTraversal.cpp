Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode *current = root, *pre = NULL;
        vector<int> inorder;
        
        while(current != NULL)
        {
            if(current -> left == NULL)
            {
                inorder.push_back(current -> val);
                current = current -> right;
            }
            else
            {
                pre = current -> left;
                while(pre -> right != NULL && pre -> right != current)
                {
                    pre = pre -> right;
                }
                if(pre -> right == NULL)
                {
                    pre -> right = current;
                    current = current -> left;
                }
                else
                {
                    pre -> right = NULL;
                    inorder.push_back(current -> val);
                    current = current -> right;
                }
            }
        }
        return inorder;
        
    }
};
