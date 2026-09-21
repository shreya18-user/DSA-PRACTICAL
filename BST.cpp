#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *root;

    // Function to insert a node into BST
    void insert(Node *&temp, int value)
    {
        if (temp == NULL)
        {
            temp = new Node;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
        }

        if (value < temp->data)
        {
            insert(temp->left, value);
        }
        else if (value > temp->data)
        {
            insert(temp->right, value);
        }
        else
        {
            cout << "\nDuplicate value not allowed!";
        }
    }

    // Inorder Traversal
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder Traversal
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Function to delete all nodes
    void destroy(Node *temp)
    {
        if (temp == NULL)
            return;

        destroy(temp->left);
        destroy(temp->right);
        delete temp;
    }

public:

    // Constructor
    Tree()
    {
        root = NULL;
    }

    // Create Binary Search Tree
    void createTree(int value)
    {
        insert(root, value);
    }

    // Insert Node
    void insertNode(int value)
    {
        insert(root, value);
    }

    // Display Inorder
    void displayInorder()
    {
        inorder(root);
    }

    // Display Preorder
    void displayPreorder()
    {
        preorder(root);
    }

    // Display Postorder
    void displayPostorder()
    {
        postorder(root);
    }

    // Destructor
    ~Tree()
    {
        destroy(root);
    }
};

int main()
{
    Tree t;
    int choice, value;

    do
    {
        cout << "\n\n============ Binary Search Tree Menu ==============";
        cout << "\n1. Create Binary Search Tree";
        cout << "\n2. Insert Node";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter value: ";
                cin >> value;
                t.createTree(value);
                cout << "\nNode inserted successfully!";
                break;

            case 2:
                cout << "\nEnter value to insert: ";
                cin >> value;
                t.insertNode(value);
                break;

            case 3:
                cout << "\nInorder Traversal: ";
                t.displayInorder();
                cout << endl;
                break;

            case 4:
                cout << "\nPreorder Traversal: ";
                t.displayPreorder();
                cout << endl;
                break;

            case 5:
                cout << "\nPostorder Traversal: ";
                t.displayPostorder();
                cout << endl;
                break;

            case 6:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
