#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// build binary tree by recursion
node *binaryTree(node *root)
{

    int data;
    cout << "enter data " << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "enter data to insert  left of " << data << endl;
    root->left = binaryTree(root->left);
    cout << "enter data to insert right of " << data << endl;
    root->right = binaryTree(root->right);
    return root;
}

// building binARY Tree through iteration 
void buildTreeIteration(node *&root)
{
    int data;
    cout << " Enter data fro root :" << endl;
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter data to insert left of  " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "enter data to insert right of  " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// level order traversal  accesing elements level by level
void levelOrderTraversal(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
// in order traversal "LNR "    left ->print node-> right
void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// preorder traversal  " NLR"  print node->Left->right
void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// postorder traversal  " LRN"       Left->right-> print node
void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;
    // root = binaryTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);
    // cout << " post order traversal" << endl;
    // inOrderTraversal(root);
    // cout << " pre order data" << endl;
    // preOrderTraversal(root);
    // cout << "\n post order data" << endl;
    // postOrderTraversal(root);
    buildTreeIteration(root);
    levelOrderTraversal(root);

    return 0;
}
