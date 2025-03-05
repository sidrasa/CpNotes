// 208. Implement Trie (Prefix Tree)
class Trie {
public:
    Trie* root;
    unordered_map<char, Trie*> child;
    bool isEnd;

    Trie() {
        root = nullptr; // Prevent infinite recursion
        isEnd = false;
    }

    void insert(string s) {
        if (!root) root = this; // Initialize root only once
        Trie* node = root;
        for (auto e : s) {
            if (node->child.find(e) == node->child.end()) {
                node->child[e] = new Trie();
            }
            node = node->child[e];
        }
        node->isEnd = true;
    }

    bool search(string s) {
        if (!root) return false;
        Trie* node = root;
        for (auto e : s) {
            if (node->child.find(e) == node->child.end()) {
                return false;
            }
            node = node->child[e];
        }
        return node->isEnd; // Must check isEnd to validate full word
    }

    bool startsWith(string s) {
        if (!root) return false;
        Trie* node = root;
        for (auto e : s) {
            if (node->child.find(e) == node->child.end()) {
                return false;
            }
            node = node->child[e];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
