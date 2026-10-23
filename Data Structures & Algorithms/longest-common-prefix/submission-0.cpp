class TrieNode {
   public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        isEnd = false;
    }
};

class Solution {
    TrieNode* root;

   public:
    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int i = c - 'a';

            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }

            node = node->children[i];
        }

        node->isEnd = true;
    }

    string checkChar() {
        string common = "";
        TrieNode* curr = root;

        while (!curr->isEnd) {
            int count = 0;
            int next = -1;

            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    count++;
                    next = i;
                }
            }

            if (count != 1) {
                break;
            }

            common += char(next + 'a');
            curr = curr->children[next];
        }

        return common;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        root = new TrieNode();

        for (string& word : strs) {
            insert(word);
        }

        return checkChar();
    }
};