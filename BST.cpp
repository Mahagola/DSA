#include <iostream>
#include <queue>
using namespace std;
//---------------------------------------
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLvlWise()
{
    int rootData;
    cout << "Enter Data :" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "enter right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
int countNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+ countNodes(root->left)+countNodes(root->right);
}
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << " L:" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R:" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

// BinaryTreeNode<int> *takeinput()
// {
//     int rootData;
//     cout << "Enter Data : " << endl;
//     cin >> rootData;
//     if (rootData == -1)
//     {
//         return NULL;
//     }
//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
//     BinaryTreeNode<int> *leftChild = takeinput();
//     BinaryTreeNode<int> *rightChild = takeinput();
//     root->left = leftChild;
//     root->right = rightChild;
//     return root;
// }

int main()
{
    BinaryTreeNode<int> *root = takeInputLvlWise();
    printTree(root);
    cout<<"number of nodes are : "<<countNodes(root);  
    delete root;
}