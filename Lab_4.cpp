#include <iostream>
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

class BST {
private:
    Node *root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr)
            return new Node(key);
        
        if (key < root->key)
            root->left = insertRecursive(root->left, key);
        else if (key > root->key)
            root->right = insertRecursive(root->right, key);

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteRecursive(Node* root, int key, int &deletedValue) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteRecursive(root->left, key, deletedValue);
        else if (key > root->key)
            root->right = deleteRecursive(root->right, key, deletedValue);
        else {
            deletedValue = root->key;
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursive(root->right, temp->key, deletedValue);
        }
        return root;
    }

    bool searchRecursive(Node* root, int key) {
        if (root == nullptr)
            return false;
        if (root->key == key)
            return true;
        if (root->key < key)
            return searchRecursive(root->right, key);
        return searchRecursive(root->left, key);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    bool remove(int key, int &deletedValue) {
        Node* temp = root;
        root = deleteRecursive(root, key, deletedValue);
        return (temp != root);
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }
};

int main() {
    BST tree;
    char choice;
    int value, deletedValue;

    do {
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case '2':
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found in the tree.\n";
                else
                    cout << "Value not found in the tree.\n";
                break;
            case '3':
                cout << "Enter value to delete: ";
                cin >> value;
                if (tree.remove(value, deletedValue))
                    cout << "Value " << deletedValue << " deleted from the tree.\n";
                else
                    cout << "Value not found in the tree. Deletion failed.\n";
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
