#include <iostream>
#include <queue>
using namespace std;

char tree[20];

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *helpBuildtree(Node *node)
    {
        int data;
        cin >> data;
        cout << endl;

        if (data == -1)
        {
            return NULL;
        }
        node = new Node(data);
        cout << "Enter you want to insert left of " << data << " : ";
        node->left = helpBuildtree(node->left);
        cout << "Enter you want to insert right of " << data << " : ";
        node->right = helpBuildtree(node->right);
        return node;
    }

    Node *buildtree()
    {
        int data;
        cout << "Enter the root element:  ";
        cin >> data;
        Node *root = new Node(data);
        cout << "Enter you want to insert left of " << data << " : ";
        root->left = helpBuildtree(root->left);
        cout << "Enter you want to insert right of " << data << " : ";
        root->right = helpBuildtree(root->right);

        return root;
    }

    void createTree(){
        root=buildtree();
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            node = new Node(value);
        }
        else if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void display()
    {
        display(root);
    }

    void display(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        display(node->left);
        cout << node->data << " ";
        display(node->right);
    }
};

int root(char key)
{
    if (tree[0] != '\0')
    {
        cout << " Tree already had root ";
    }
    else
    {
        tree[0] = key;
    }
    return 0;
}

int left(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "\n Can't set child at " << (parent * 2) + 1 << " , no parent found";
    }
    else
    {
        tree[(parent * 2) + 1] = key;
    }
    return 0;
}

int right(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "\n Can't set child at "
             << (parent * 2) + 2
             << " , no parent found ";
    }
    else
    {
        tree[(parent * 2) + 2] = key;
    }
    return 0;
}

int print_tree()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
        {
            cout << tree[i];
        }
        else
        {
            cout << "-";
        }
    }
    return 0;
}

int main()
{
    // cout << "Enter the root character : ";
    // char character;
    // cin >> character;
    // root(character);
    // while (true)
    // {
    //     cout << "Enter which set you want to add if left=0 if right=1 if you want to end the 2 : " << endl;
    //     int x;
    //     cin >> x;
    //     if (x == 0)
    //     {
    //         cout << " Enter character : ";
    //         char ch;
    //         cin >> ch;
    //         cout << " Enter Level : ";
    //         int level;
    //         cin >> level;
    //         left(ch, level);
    //     }
    //     else if (x == 1)
    //     {
    //         cout << " Enter character : ";
    //         char ch;
    //         cin >> ch;
    //         cout << " Enter Level : ";
    //         int level;
    //         cin >> level;
    //         right(ch, level);
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // print_tree();

    // By linked list
    BST* tree=new BST();
    tree->insert(3);
    tree->insert(7);
    tree->insert(4);
    tree->insert(23);
    tree->insert(13);
    tree->insert(30);
    tree->insert(25);
    // 10 20 40 -1 -1 50 3 -1 -1 -1 30 5 -1 -1 4 -1 -1
    // tree->createTree();

    tree->display();

    return 0;
}