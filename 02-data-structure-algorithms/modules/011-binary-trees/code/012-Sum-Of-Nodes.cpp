#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << f->data << " : ";
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftChild);
            f->left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child of " << f->data << " : ";
        int rightChild;
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightChild);
            f->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int rootData = root->data;
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    return rootData + leftSum + rightSum;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);
}
