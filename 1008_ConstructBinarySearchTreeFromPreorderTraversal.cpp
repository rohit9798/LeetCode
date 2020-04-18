Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        TreeNode *root = new TreeNode(preorder[i++]);
        stack<TreeNode*> s;
        s.push(root);
        while(i < preorder.size())
        {
            TreeNode *temp;
            while(i < preorder.size())
            {
                temp = s.top();
                if(temp -> val >= preorder[i])
                {
                    temp -> left = new TreeNode(preorder[i]);
                    s.push(temp -> left);
                }
                else
                    break;
                i++;
            }
            if(i < preorder.size())
            {
                TreeNode *prev;
                while(!s.empty() && s.top() -> val < preorder[i])
                {
                    prev = s.top();
                    s.pop();
                }
                prev -> right = new TreeNode(preorder[i++]);
                s.push(prev -> right);
            }
        }
        return root;
    }
};
