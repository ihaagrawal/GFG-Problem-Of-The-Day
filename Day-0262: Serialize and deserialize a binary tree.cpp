// Serialize and deserialize a binary tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    vector<int> serialize(Node *root) {
        vector<int> result;
        serializeHelper(root, result);
        return result;
    }

    void serializeHelper(Node *root, vector<int> &result) {
        if (!root) {
            result.push_back(-1);
            return;
        }
        result.push_back(root->data);
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    Node *deSerialize(vector<int> &arr) {
        int index = 0;
        return deSerializeHelper(arr, index);
    }

    Node *deSerializeHelper(vector<int> &arr, int &index) {
        if (index >= arr.size() || arr[index] == -1) {
            index++;
            return nullptr;
        }
        Node *root = new Node(arr[index++]);
        root->left = deSerializeHelper(arr, index);
        root->right = deSerializeHelper(arr, index);
        return root;
    }
};
