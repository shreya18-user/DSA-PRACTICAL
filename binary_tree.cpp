#include <iostream>
#include <string>
using namespace std;

// Node structure for Binary Tree
struct Node {
    string bookName;
    Node* left;
    Node* right;

    Node(string name) {
        bookName = name;
        left = right = NULL;
    }
};

// Insert book into Binary Tree
Node* insert(Node* root, string book) {
    if (root == NULL)
        return new Node(book);

    if (book < root->bookName)
        root->left = insert(root->left, book);
    else
        root->right = insert(root->right, book);

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->bookName << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->bookName << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->bookName << " ";
    }
}

int main() {
    Node* root = NULL;
    int n;
    string book;

    cout << "Enter number of books: ";
    cin >> n;

    cin.ignore();

    cout << "Enter book names:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, book);
        root = insert(root, book);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}