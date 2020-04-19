Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


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
    void inorder(TreeNode* root, vector<int> &array)
    {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* temp = root -> left;
        while(!s.empty() || temp != NULL)
        {
            while(temp != NULL)
            {
                s.push(temp);
                temp = temp -> left;
            }
            temp = s.top();
            array.push_back(temp -> val);
            s.pop();
            temp = temp -> right;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> inorder1, inorder2;
        vector<int> result;
        if(root1 != NULL)
            inorder(root1, inorder1);
        if(root2 != NULL)
            inorder(root2, inorder2);
        int i = 0, j = 0;
        while(i < inorder1.size() && j < inorder2.size())
        {
            if(inorder1[i] < inorder2[j])
            {
                result.push_back(inorder1[i]);
                i++;
            }
            else
            {
                result.push_back(inorder2[j]);
                j++;
            }
        }
        while(i < inorder1.size())
        {
            result.push_back(inorder1[i]);
            i++;
        }
        while(j < inorder2.size())
        {
            result.push_back(inorder2[j]);
            j++;
        }
        return result;
    }
};
