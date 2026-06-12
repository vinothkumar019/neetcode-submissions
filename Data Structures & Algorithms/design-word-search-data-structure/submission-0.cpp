class WordDictionary {
public:
     WordDictionary* child[26];
     bool isEnd;
    WordDictionary() {
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
    
    void addWord(string word) {
         WordDictionary* node=this;
         for(char ch:word){
            int idx=ch-'a';
            if(node->child[idx]==nullptr){
                node->child[idx] = new WordDictionary(); 
            }
            node=node->child[idx];
         }
         node->isEnd=true;
    }
    bool dfs(string &word,int pos,WordDictionary* node){
        if(pos==word.size()) return node->isEnd;
        char ch=word[pos];

        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(node->child[i] && dfs(word,pos+1,node->child[i])) return true;
            }
            return false;
        }
        int idx=ch-'a';
        if(node->child[idx] == nullptr) return false;

        return dfs(word,pos+1,node->child[idx]);
    
    }
    bool search(string word) {
        return dfs(word,0,this);
    }
};
