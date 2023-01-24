#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//---------------------------------------
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};
TreeNode<int> *takeInputLvlWise()
{
    int rootData;
    cout << "enter root data :" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data :" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
//----------------------------------------

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    { // edge case
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
//------------------------------------
int main()
{
    // TreeNode<int> *root = new TreeNode<int>(50);
    // TreeNode<int> *child1 = new TreeNode<int>(30);
    // TreeNode<int> *child2 = new TreeNode<int>(40);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // TreeNode<int> *root = takeInput();
    TreeNode<int>*root=takeInputLvlWise();
    printTree(root);
}