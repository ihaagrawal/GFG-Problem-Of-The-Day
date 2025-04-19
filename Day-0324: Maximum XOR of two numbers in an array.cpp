// Maximum XOR of two numbers in an array (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1

class TrieNode {
public:
    TrieNode *child[2]; // 0 and 1
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) { // 32 bits for integers
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (node->child[oppositeBit]) { // Prefer opposite bit for max XOR
                maxXor |= (1 << i);
                node = node->child[oppositeBit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int maxXor(vector<int> &arr) {
        Trie trie;
        for (int num : arr) {
            trie.insert(num);
        }

        int maxResult = 0;
        for (int num : arr) {
            maxResult = max(maxResult, trie.findMaxXor(num));
        }
        return maxResult;
    }
};
