#include<iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* root;
    
    // Helper function for insert
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }
        
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        
        return node;
    }
    
    // Helper function for inorder traversal
    void inorderHelper(TreeNode* node) {
        if (node == NULL) return;
        
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    // Helper function for preorder traversal
    void preorderHelper(TreeNode* node) {
        if (node == NULL) return;
        
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    // Helper function for postorder traversal
    void postorderHelper(TreeNode* node) {
        if (node == NULL) return;
        
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    
    // Helper function for search
    bool searchHelper(TreeNode* node, int val) {
        if (node == NULL) return false;
        
        if (node->data == val) return true;
        
        if (val < node->data) {
            return searchHelper(node->left, val);
        } else {
            return searchHelper(node->right, val);
        }
    }
    
public:
    BinaryTree() {
        root = NULL;
    }
    
    // Insert a value into the tree
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    // Inorder traversal (Left, Root, Right)
    void inorder() {
        cout << "Inorder traversal: ";
        inorderHelper(root);
        cout << endl;
    }
    
    // Preorder traversal (Root, Left, Right)
    void preorder() {
        cout << "Preorder traversal: ";
        preorderHelper(root);
        cout << endl;
    }
    
    // Postorder traversal (Left, Right, Root)
    void postorder() {
        cout << "Postorder traversal: ";
        postorderHelper(root);
        cout << endl;
    }
    
    // Search for a value in the tree
    bool search(int val) {
        return searchHelper(root, val);
    }
};

int main() {
    BinaryTree tree;
    
    // Insert some values
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    
    // Perform traversals
    tree.inorder();
    tree.preorder();
    tree.postorder();
    
    // Search for values
    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not found") << endl;
    cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not found") << endl;
    
    return 0;
}
