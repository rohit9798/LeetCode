Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).




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
    vector<TreeNode*> remove(vector<TreeNode*> &next)
    {
        vector<TreeNode*> temp;
        int left = 0, right = next.size() - 1;
        while(left <= right && next[left] == NULL)
            left++;
        while(left <= right && next[right] == NULL)
            right--;
        for(int i = left; i <= right; i++)
            temp.push_back(next[i]);
        return temp;
    }
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        vector<TreeNode*> q;
        int result = 1;
        q.push_back(root);
        while(q.size() != 0)
        {
            vector<TreeNode*> next;
            for(int i = 0; i < q.size(); i++)
            {
                TreeNode* temp = q[i];
                if(temp != NULL)
                {
                    next.push_back(temp -> left);
                    next.push_back(temp -> right);
                }
                else
                {
                    next.push_back(NULL);
                    next.push_back(NULL);
                }
            }
            next = remove(next);
            result = max(result, (int)(next.size()));
            q = next;
        }
        return result;
    }
};
