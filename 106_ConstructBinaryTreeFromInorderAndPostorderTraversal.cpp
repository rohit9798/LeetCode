Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
   
   
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
    int index(vector<int> &A, int start, int end, int val)
    {
        int i = start;
        while(i <= end)
        {
            if(A[i] == val)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
    TreeNode* build(vector<int> &A, vector<int> &B, int start, int end, int &t)
    {
        if(start > end)
            return NULL;
        int val = B[t--];
        TreeNode* ptr = new TreeNode(val);
        if(start == end)
            return ptr;
        int i = index(A, start, end, val);
        ptr -> right = build(A, B, i + 1, end, t);
        ptr -> left = build(A, B, start, i - 1, t);

        return ptr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int t = postorder.size() - 1;
        TreeNode* root = build(inorder, postorder, 0, t, t);
        return root;
    }
};
