class TrieNode {
   public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            int i = c - 'a';

            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }

            cur = cur->children[i];
        }

        cur->endOfWord = true;
    }

    bool search(string word) { return dfs(root, word, 0); }

   private:
    bool dfs(TrieNode* cur, string& word, int index) {
        if (index == word.size()) {
            return cur->endOfWord;
        }
        char c = word[index];

        if (c != '.') {
            int i = c - 'a';

            if (cur->children[i] == nullptr) {
                return false;
            }

            return dfs(cur->children[i], word, index + 1);
        }

        for (int i = 0; i < 26; i++) {
            if (cur->children[i] != nullptr) {
                if (dfs(cur->children[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};