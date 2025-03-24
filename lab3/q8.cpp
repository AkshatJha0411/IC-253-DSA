#include <iostream>
#define MAX 5 // Maximum capacity of the circular queue

using namespace std;

class CircularQueue {
public:
    int front, rear, size;
    int queue[MAX];
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == MAX;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int customerID) {
        if (isFull()) {
            cout << "Queue is full! No more customers can be added.\n";
            return;
        }
        
        rear = (rear + 1) % MAX;
        queue[rear] = customerID;
        size++;
        
        if (front == -1) front = 0; // Set front to 0 on first insertion
        
        cout << "Customer " << customerID << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No tickets to allocate.\n";
            return;
        }
        
        cout << "Allocating ticket to Customer " << queue[front] << "\n";
        front = (front + 1) % MAX;
        size--;
        
        if (size == 0) { // Reset front and rear when queue becomes empty
            front = -1;
            rear = -1;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        
        cout << "Current Queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX;
            cout << queue[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue ticketQueue;
    int choice, customerID;

    do {
        cout << "\nTicket Booking System\n";
        cout << "1. Add Customer\n";
        cout << "2. Allocate Ticket\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> customerID;
                ticketQueue.enqueue(customerID);
                break;
            case 2:
                ticketQueue.dequeue();
                break;
            case 3:
                ticketQueue.displayQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
