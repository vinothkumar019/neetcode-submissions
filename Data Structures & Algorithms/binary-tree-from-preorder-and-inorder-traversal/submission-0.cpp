class Solution {
public:
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inStart;

        while (idx <= inEnd) {
            if (inorder[idx] == rootVal)
                break;
            idx++;
        }

        int leftSize = idx - inStart;

        root->left = build(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           idx - 1);

        root->right = build(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            idx + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        return build(preorder, inorder,
                     0, n - 1,
                     0, n - 1);
    }
};