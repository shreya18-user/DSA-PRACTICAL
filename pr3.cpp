#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList()
    {
        head = NULL;
    }

    void createList()
    {
        int n, value;

        cout << "\nEnter Number of Nodes: ";
        cin >> n;

        if(n <= 0)
        {
            cout << "\nInvalid number of nodes.";
            return;
        }

        for(int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;
            insertEnd(value);
        }

        cout << "\nLinked List created Successfully\n";
    }


    // Insert node at the end
    void insertEnd(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "\nNode inserted successfully.";
    }


    // Delete node
    void deleteNode()
    {
        int value;

        if(head == NULL)
        {
            cout << "\nLinked List is empty.";
            return;
        }

        cout << "\nEnter value to delete: ";
        cin >> value;


        if(head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "\nNode deleted successfully.";
            return;
        }


        Node* temp = head;

        while(temp->next != NULL && temp->next->data != value)
        {
            temp = temp->next;
        }


        if(temp->next == NULL)
        {
            cout << "\nNode not found.";
        }
        else
        {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;

            cout << "\nNode deleted successfully.";
        }
    }


    // Display linked list
    void display()
    {
        if(head == NULL)
        {
            cout << "\nLinked List is empty.";
            return;
        }

        Node* temp = head;

        cout << "\nLinked List Elements: ";

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


int main()
{
    LinkedList list;
    int choice;

    do
    {
        cout << "\n========== Linked List ==========";
        cout << "\n1. Create List";
        cout << "\n2. Insert Node";
        cout << "\n3. Delete Node";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                list.createList();
                break;

            case 2:
            {
                int value;
                cout << "\nEnter value to insert: ";
                cin >> value;
                list.insertEnd(value);
                break;
            }

            case 3:
                list.deleteNode();
                break;

            case 4:
                list.display();
                break;

            case 5:
                cout << "\nProgram Exit";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    }while(choice != 5);


    return 0;
}
