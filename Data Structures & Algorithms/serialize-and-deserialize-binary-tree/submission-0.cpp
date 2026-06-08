class Codec {
public:

    string res;

    void serializeDFS(TreeNode* root) {

        if (!root) {
            res += "N,";
            return;
        }

        res += to_string(root->val) + ",";

        serializeDFS(root->left);
        serializeDFS(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        res = "";
        serializeDFS(root);

        return res;
    }

    TreeNode* deserializeDFS(vector<string>& nodes, int& idx) {

        if (nodes[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++;

        root->left = deserializeDFS(nodes, idx);
        root->right = deserializeDFS(nodes, idx);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> nodes;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            if (!token.empty())
                nodes.push_back(token);
        }

        int idx = 0;

        return deserializeDFS(nodes, idx);
    }
};