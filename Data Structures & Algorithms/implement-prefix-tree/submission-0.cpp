class PrefixTree {
public:
    PrefixTree* child[26];
    bool isEnd;
    PrefixTree() {
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
    
    void insert(string word) {
        PrefixTree* node=this;
        for(char ch: word){
            int idx=ch - 'a';
            if(node->child[idx] == nullptr){
                node->child[idx]= new PrefixTree();
            }
            node=node->child[idx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        PrefixTree* node=this;
        for(char ch:word){
            int idx=ch-'a';
            if(node->child[idx] == nullptr) return false;
            node=node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node=this;
        for(char ch:prefix){
            int idx=ch-'a';
            if(node->child[idx] == nullptr) return false;
            node=node->child[idx];
        }
        return true;
    }
};
