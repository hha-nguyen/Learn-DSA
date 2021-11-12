#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int countOfNode (Node* root){
        if (root == NULL) {
            return 0;
        }
        return countOfNode(root->left) + countOfNode(root->right) +1;
    }
    
    Node* searchNode(Node* root, int key) {
        if (root == NULL) {
            return NULL;
        } else {
            if (root->data == key) {
                return root;
            } else {
                Node* foundNode = searchNode(root->left, key);
                if (foundNode == NULL) {
                    foundNode = searchNode(root->right, key);
                }
                return foundNode;
            }
        }
    }

    void insertion(Node *root, int parent, int key) {
        if (root == NULL) return;
        if (root->data == parent) {
            if (root->left == NULL) {
                root->left = new Node(key);
            } else {
                root->right = new Node(key);
            }
        }
        insertion(root->left, parent, key);
        insertion(root->right, parent, key);
    }

    void preOrder(Node* root){
        if (root == NULL) return;
        cout << root->data << endl;
        preOrder(root->left);
        preOrder(root->right);
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return max(height(node->left), height(node->right)) + 1;
    }

    bool isBalanced(Node* root) {
        int lh;
        int rh;

        if (root == NULL) return 1;

        lh = height(root->left);
        rh = height(root->right);

        if (abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return 1;
        return 0;
    }
};

int main(){
    Solution myTree;
    Node* root = NULL;

    int n;
    int error = 0;

    cin >> n;
    while(myTree.countOfNode(root) + error < n) {
        Node* temp;
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (myTree.countOfNode(root) == 0) {
            root = new Node(temp1);
            if (root->left == NULL) {
                root->left = new Node(temp2);
            } else root->right = new Node(temp2);
        } else if (myTree.searchNode(root, temp1) != NULL){
            temp = myTree.searchNode(root, temp1);
            if (temp->left != NULL && temp->right != NULL) {
                error++;
                continue;
            } else {
                myTree.insertion(root, temp1, temp2);
            }
        } else if (myTree.searchNode(root, temp1) == NULL){
            error++;
            continue;}
    }
    //myTree.preOrder(root);
    if (myTree.isBalanced(root)) cout << "yes" << endl;
    else cout << "no" << endl;
}