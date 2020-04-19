Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200



class Solution {
public:
    void inorder(TreeNode* root, vector<int> &array)
    {
        if(root != NULL)
        {
            inorder(root -> left, array);
            if(root -> left == NULL && root -> right == NULL)
                array.push_back(root -> val);
            inorder(root -> right, array);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> trace1, trace2;
        inorder(root1, trace1);
        inorder(root2, trace2);
        return trace1 == trace2;
        
    }
};
