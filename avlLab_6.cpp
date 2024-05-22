#include <iostream>
#include <cstdlib> // for malloc and free

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    TreeNode* root;

    AVLTree() : root(nullptr) {}

    TreeNode* createNode(int data) {
        return new TreeNode(data);
    }

    int getHeight(TreeNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(TreeNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    TreeNode* insertNode(TreeNode* root, int data) {
        if (root == nullptr)
            return createNode(data);

        if (data < root->data)
            root->left = insertNode(root->left, data);
        else if (data > root->data)
            root->right = insertNode(root->right, data);
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        if (balance > 1 && data < root->left->data)
            return rightRotate(root);
        if (balance < -1 && data > root->right->data)
            return leftRotate(root);
        if (balance > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && data < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    bool isAVL(TreeNode* root) {
        if (root == nullptr)
            return true;

        int balance = getBalanceFactor(root);

        return abs(balance) <= 1 && isAVL(root->left) && isAVL(root->right);
    }

    void printRotationCases(int data) {
        root = insertNode(root, data);

        if (isBalanced(root))
            cout << "The tree is balanced.\n";
        else {
            cout << "The tree is imbalanced.\n";
            int balance = getBalanceFactor(root);
            cout << "Balance factor: " << balance << endl;
            if (balance > 1 && data < root->left->data)
                cout << "Left-Left rotation needed.\n";
            else if (balance < -1 && data > root->right->data)
                cout << "Right-Right rotation needed.\n";
            else if (balance > 1 && data > root->left->data) {
                cout << "Left-Right rotation needed.\n";
                cout << "Performing Left-Right rotation...\n";
                root->left = leftRotate(root->left);
                root = rightRotate(root);
                cout << "Rotation performed.\n";
            } else if (balance < -1 && data < root->right->data) {
                cout << "Right-Left rotation needed.\n";
                cout << "Performing Right-Left rotation...\n";
                root->right = rightRotate(root->right);
                root = leftRotate(root);
                cout << "Rotation performed.\n";
            }
        }
    }

    void freeTree(TreeNode* root) {
        if (root == nullptr)
            return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};

int main() {
    AVLTree tree;
    int choice, data;

    do {
        cout << "\n----- AVL Tree Operations -----\n";
        cout << "1. Insert Node\n";
        cout << "2. Check if Balanced\n";
        cout << "3. Check if AVL\n";
        cout << "4. Check Rotation Cases\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.root = tree.insertNode(tree.root, data);
                break;
            case 2:
                if (tree.isBalanced(tree.root))
                    cout << "The tree is balanced.\n";
                else
                    cout << "The tree is not balanced.\n";
                break;
            case 3:
                if (tree.isAVL(tree.root))
                    cout << "The tree is an AVL tree.\n";
                else
                    cout << "The tree is not an AVL tree.\n";
                break;
            case 4:
                cout << "Enter data to check rotation cases: ";
                cin >> data;
                tree.printRotationCases(data);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);

    tree.freeTree(tree.root);

    return 0;
}


#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;

    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        return x;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

       void inorderTraversal(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stack;
        Node* curr = root;

        while (curr != nullptr || !stack.empty()) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            cout << curr->key << " ";
            curr = curr->right;
        }
    }

    void preorderTraversal(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stack;
        stack.push(root);

        while (!stack.empty()) {
            Node* curr = stack.top();
            stack.pop();
            cout << curr->key << " ";

            if (curr->right) stack.push(curr->right);
            if (curr->left) stack.push(curr->left);
        }
    }

    void postorderTraversal(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            Node* curr = stack1.top();
            stack1.pop();
            stack2.push(curr);

            if (curr->left) stack1.push(curr->left);
            if (curr->right) stack1.push(curr->right);
        }

        while (!stack2.empty()) {
            Node* curr = stack2.top();
            stack2.pop();
            cout << curr->key << " ";
        }
    }

    bool isBalanced(Node* node) {
        if (node == nullptr) return true;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(node->left) &&
            isBalanced(node->right)) {
            return true;
        }

        return false;
    }

    bool isAVL(Node* node) {
        if (node == nullptr) return true;

        int balance = balanceFactor(node);

        if (abs(balance) <= 1 &&
            isAVL(node->left) &&
            isAVL(node->right)) {
            return true;
        }

        return false;
    }

    void checkAndPerformRotations(Node* node) {
        int balance = balanceFactor(node);

        if (balance > 1 && balanceFactor(node->left) >= 0) {
            cout << "Left-Left (LL) Rotation needed on node " << node->key << "\n";
            rightRotate(node);
        }
        else if (balance > 1 && balanceFactor(node->left) < 0) {
            cout << "Left-Right (LR) Rotation needed on node " << node->key << "\n";
            node->left = leftRotate(node->left);
            rightRotate(node);
        }
        else if (balance < -1 && balanceFactor(node->right) <= 0) {
            cout << "Right-Right (RR) Rotation needed on node " << node->key << "\n";
            leftRotate(node);
        }
        else if (balance < -1 && balanceFactor(node->right) > 0) {
            cout << "Right-Left (RL) Rotation needed on node " << node->key << "\n";
            node->right = rightRotate(node->right);
            leftRotate(node);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder() {
        inorderTraversal(root);
        cout << "\n";
    }

    void preorder() {
        preorderTraversal(root);
        cout << "\n";
    }

    void postorder() {
        postorderTraversal(root);
        cout << "\n";
    }

    void checkBalance() {
        if (isBalanced(root))
            cout << "The tree is balanced.\n";
        else
            cout << "The tree is not balanced.\n";
    }

    void checkAVL() {
        if (isAVL(root))
            cout << "The tree is an AVL tree.\n";
        else
            cout << "The tree is not an AVL tree.\n";
    }

    void checkRotations() {
        checkAndPerformRotations(root);
    }
};

int main() {
    AVLTree tree;
    char choice;
    int value;

    do {
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Check Balance\n";
        cout << "6. Check AVL\n";
        cout << "7. Check Rotations\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case '2':
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case '3':
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case '4':
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case '5':
                tree.checkBalance();
                break;
            case '6':
                tree.checkAVL();
                break;
            case '7':
                tree.checkRotations();
                break;
            case '8':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '8');

    return 0;
}
