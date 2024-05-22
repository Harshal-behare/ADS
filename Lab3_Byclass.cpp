#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void printLeafNodes(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

void mirror(TreeNode* root) {
    if (root == nullptr) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;
    
    cout << "Total number of nodes: " << countNodes(root) << endl;
    cout << "Total number of leaf nodes: " << countLeafNodes(root) << endl;
    
    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;
    
    cout << "Height of the tree: " << height(root) << endl;
    
    mirror(root);
    cout << "Inorder traversal of the mirror image: ";
    inorder(root);
    cout << endl;
    
    return 0;
}

// with user input

#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the tree
TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to count the total number of nodes in the tree
int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaf nodes in the tree
int countLeafNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to print the leaf nodes of the tree
void printLeafNodes(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Function to find the height of the tree
int height(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Function to create a mirror image of the tree
void mirror(TreeNode* root) {
    if (root == nullptr) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

// Function to perform an inorder traversal of the tree
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int choice, value;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Count total number of nodes\n";
        cout << "3. Count total number of leaf nodes\n";
        cout << "4. Print leaf nodes\n";
        cout << "5. Find height of the tree\n";
        cout << "6. Create mirror image of the tree\n";
        cout << "7. Display inorder traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Total number of nodes: " << countNodes(root) << endl;
                break;
            case 3:
                cout << "Total number of leaf nodes: " << countLeafNodes(root) << endl;
                break;
            case 4:
                cout << "Leaf nodes: ";
                printLeafNodes(root);
                cout << endl;
                break;
            case 5:
                cout << "Height of the tree: " << height(root) << endl;
                break;
            case 6:
                mirror(root);
                cout << "Mirror image created.\n";
                break;
            case 7:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    
    return 0;
}
