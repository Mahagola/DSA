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
    //destructor to delete the tree
    ~TreeNode(){
        for(int i=0;i<root->children.size();i++){
            delete children[i];
        }
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
// to count number of nodes
int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}
// to find heigth of the tree
int height(TreeNode<int> *root)
{
    int h = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int ch = height(root->children[i]);
        h = max(h, ch);
    }
    h += 1;
    return h;
}

// to find nodes at a particular level
void nodesAtlevel(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        nodesAtlevel(root->children[i], k - 1);
    }
}

//to find number of leaves
int leafNodes(TreeNode<int> *root)
{
    int leaf = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        leaf += leafNodes(root->children[i]);
    }
    return leaf;
}
//preorder traversal
void preOrder(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
}
//------------------------------------
int main()
{
    TreeNode<int> *root = takeInputLvlWise();
    printTree(root);
    int lvl;
    cout << "number of nodes are : " << numNodes(root) << endl;
    cout << "Height of the tree is  : " << height(root) << endl;
    cout << "Enter level : " << endl;
    cin >> lvl;
    cout << "nodes at level " << lvl << " are  : " << endl;
    nodesAtlevel(root, lvl);
    cout << " no. of leaves : " << leafNodes(root);
    cout<<"Pre-order traversal : "<<endl;
    preOrder(root);
    delete root;

}