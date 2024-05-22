#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    TreeNode* insertRec(TreeNode* node, int data) {
        if (!node) return new TreeNode(data);
        if (data < node->data) node->left = insertRec(node->left, data);
        else node->right = insertRec(node->right, data);
        return node;
    }

    void inorderRec(TreeNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(TreeNode* node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values to insert into the BST:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Inorder traversal of the BST: ";
    tree.inorder();

    cout << "Preorder traversal of the BST: ";
    tree.preorder();

    cout << "Postorder traversal of the BST: ";
    tree.postorder();

    return 0;
}
