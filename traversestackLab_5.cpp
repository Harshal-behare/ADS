#include <iostream>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }


private:
    TreeNode* insertRec(TreeNode* node, int data) {
        if (!node) return new TreeNode(data);
        if (data < node->data) node->left = insertRec(node->left, data);
        else node->right = insertRec(node->right, data);
        return node;
    }
};

class TreeTraversal
{
private:
    TreeNode *root;

public:
    TreeTraversal(TreeNode *rootNode)
    {
        root = rootNode;
    }

    void inorderTraversal()
    {
        stack<TreeNode *> s;
        TreeNode *current = root;

        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorderTraversal()
    {
        stack<TreeNode *> s;
        if (root != nullptr)
            s.push(root);

        while (!s.empty())
        {
            TreeNode *current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right != nullptr)
                s.push(current->right);
            if (current->left != nullptr)
                s.push(current->left);
        }
    }

    void postorderTraversal()
    {
        if (root == nullptr)
            return;

        stack<TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left != nullptr)
                s1.push(current->left);
            if (current->right != nullptr)
                s1.push(current->right);
        }

        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
};

int main()
{
BST tree;
    int n, value;
    TreeNode *root=tree.root;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values to insert into the BST:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    TreeTraversal treeTraversal(root);

    cout << "Inorder traversal: ";
    treeTraversal.inorderTraversal();
    cout << endl;

    cout << "Preorder traversal: ";
    treeTraversal.preorderTraversal();
    cout << endl;

    cout << "Postorder traversal: ";
    treeTraversal.postorderTraversal();
    cout << endl;

    return 0;
}
