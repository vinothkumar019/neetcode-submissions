class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        word = "";

        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
public:
    vector<string> ans;
    TrieNode* root;

    void insert(string word) {

        TrieNode* node = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(node->child[idx] == nullptr) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node) {

        if(r < 0 ||
           r >= board.size() ||
           c < 0 ||
           c >= board[0].size() ||
           board[r][c] == '#')
            return;

        char ch = board[r][c];

        if(node->child[ch - 'a'] == nullptr)
            return;

        node = node->child[ch - 'a'];

        if(node->word != "") {
            ans.push_back(node->word);

            // avoid duplicates
            node->word = "";
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node);
        dfs(board, r - 1, c, node);
        dfs(board, r, c + 1, node);
        dfs(board, r, c - 1, node);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        if(board.empty())
            return {};

        root = new TrieNode();

        for(string word : words) {
            insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return ans;
    }
};