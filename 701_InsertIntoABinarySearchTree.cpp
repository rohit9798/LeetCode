Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4




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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *ptr = root;
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        while(ptr -> left || ptr -> right)
        {
            if(ptr -> val > val)
            {
                if(ptr -> left == NULL)
                    break;
                ptr = ptr -> left;
            }
            else
            {
                if(ptr -> right == NULL)
                    break;
                ptr = ptr -> right;
            }
        }
        if(ptr -> val > val)
        {
            ptr -> left = new TreeNode(val);
        }
        else
        {
            ptr -> right = new TreeNode(val);
        }
        return root;
    }
};
