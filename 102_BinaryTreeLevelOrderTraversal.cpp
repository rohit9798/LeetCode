Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<pair<TreeNode*, int>> q;
        int index = 0;
        vector<int> temp;
        q.push({root, index});
        while(!q.empty())
        {
            temp.clear();
            while(!q.empty())
            {
                TreeNode* ptr = q.front().first;
                int i = q.front().second;
                if(i == index)
                {
                    temp.push_back(ptr -> val);
                    if(ptr -> left)
                        q.push({ptr -> left, index + 1});
                    if(ptr -> right)
                        q.push({ptr -> right, index + 1});
                    q.pop();
                }
                else
                    break;
            }
            index++;
            result.push_back(temp);
        }
        return result;
    }
};
