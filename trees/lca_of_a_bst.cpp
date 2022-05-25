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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        
        TreeNode* result = root;
        
        if(p->val < root->val && q->val < root->val)
        {
            result = lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val)
        {
            result = lowestCommonAncestor(root->right, p, q);
        }
        
        return result;
    }

    TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL)
        {
            if(p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        
        return root;
    }
};
