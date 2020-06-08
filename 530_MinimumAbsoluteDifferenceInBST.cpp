Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).



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
    void inorder(TreeNode *root, int &count, vector<int> &temp)
    {
        if(root != NULL && count < 2)
        {
            inorder(root -> left, count, temp);
            temp.push_back(root -> val);
            inorder(root -> right, count, temp);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        
        int count = 0, minimum = INT_MAX;
        vector<int> temp;
        inorder(root, count, temp);
        for(int i = 1; i < temp.size(); i++)
        {
            minimum = min(minimum, temp[i] - temp[i - 1]);
        }
        return minimum;
    }
};
