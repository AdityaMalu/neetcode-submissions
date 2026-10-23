class TrieNode{
    public:
    TrieNode* childern[26];
    bool endOfWord;

    TrieNode(){
        for(int i = 0 ; i < 26; i++){
            childern[i] = nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i  = c - 'a';
            if(cur->childern[i] == nullptr){
                cur->childern[i] = new TrieNode();
            }
            cur = cur->childern[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word){
            int i  = c - 'a';
            if(cur->childern[i] == nullptr){
                return false;
            }
            cur = cur->childern[i];
        }
        return cur->endOfWord == true;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix ){
            int i  = c - 'a';
            if(cur->childern[i] == nullptr){
                return false;
            }
            cur = cur->childern[i];
        }
        return true;
    }
};
