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
    int count=0;
    int ans=0;
    int inorder(TreeNode* root,int k){
        if(!root) return 0;
        inorder(root->left,k);
        count++;
        if(count == k) ans= root->val;
        inorder(root->right,k);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
       return inorder(root,k);
    }
};
