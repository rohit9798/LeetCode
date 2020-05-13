Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.



/*
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
    bool find(TreeNode* root, TreeNode* p)
    {
        if(root == NULL)
            return false;
        if(root == p)
            return true;
        return find(root -> left, p) || find(root -> right, p);
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return NULL;
        
        bool right_q = find(root -> right, q);
        bool right_p = find(root -> right, p);
        bool left_p = find(root -> left, p);
        bool left_q = find(root -> left, q);
        if((root == p && right_q) || (root == q && right_p) || (root == q && left_p) || (root == p && left_q))
            return root;
        
        if((left_p && right_q) || (right_p && left_q))
            return root;
        if(left_p && left_q)
            return LCA(root -> left, p, q);
        if(right_p && right_q)
            return LCA(root -> right, p, q);
        return NULL;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p == q)
            return p;
        return LCA(root, p, q);
        
    }
};
