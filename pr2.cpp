#include <iostream>
using namespace std;

class Queue{
    int queue[5];
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    void enqueue(int value){
        if(rear == size-1){
            cout << "\nQueue is overflow.\n";
            return;
        }

        if(front == -1){
            front = 0;
        }

        rear++;
        queue[rear] = value;
        cout << "\nElement inserted successfully.\n";
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout << "\nQueue Underflow! Queue is empty.\n";
            front = rear = -1;
            return;
        }

        cout << "\nDeleted Element: " << queue[front] << endl;
        front++;
    }

    void display(){
        if(front == -1 || front > rear){
            cout << "\nQueue is Empty.\n";
            return;
        }

        cout << "\nQueue Elements : ";
        for(int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do{
        cout << "\n=============Queue=================\n";
        cout << "\n 1.Enqueue";
        cout << "\n 2.Dequeue";
        cout << "\n 3.Display";
        cout << "\n 4.Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice){

        case 1:
            cout << "\nEnter Elements: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program Exit";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    }while(choice != 4);

    return 0;
}
