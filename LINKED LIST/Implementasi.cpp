#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Insert at beginning
    void insertBegin(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    // Insert after a given value
    void insertAfter(int valueToInsert, int afterValue) {
        if (!head) return;

        Node* current = head;
        do {
            if (current->data == afterValue) {
                Node* newNode = new Node(valueToInsert);
                Node* nextNode = current->next;

                current->next = newNode;
                newNode->prev = current;
                newNode->next = nextNode;
                nextNode->prev = newNode;

                return;
            }
            current = current->next;
        } while (current != head);
    }

    // Display forward and backward
    void display() {
        if (!head) {
            cout << "List kosong.\n";
            return;
        }

        Node* temp = head;
        cout << "\nTraversal maju: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\nTraversal mundur: ";
        Node* tail = head->prev;
        temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertEnd(5);
    cdll.insertBegin(4);
    cdll.insertEnd(7);
    cdll.insertEnd(8);
    cdll.insertAfter(6, 5); // insert 6 after 5

    cout << "Circular Doubly Linked List yang dibuat:\n";
    cdll.display();

    return 0;
}

