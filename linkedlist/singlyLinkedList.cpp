#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    ~SinglyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int value)
    {
        if (pos == 0)
        {
            insertAtHead(value);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if(head -> next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (pos == 0)
        {
            deleteFromStart();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)  return;
           

        Node *deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
    }

    void deleteByValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if(head -> data == value){
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next->data == value)
            {
                Node *deleteNode = temp->next;

                temp->next = temp->next->next;
                delete deleteNode;
                return;
            }
            temp = temp->next;
        }
    }

    void updateByIndex(int pos, int value)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        temp->data = value;
    }

    void updateByValue(int oldValue, int newValue)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == oldValue)
            {
                temp->data = newValue;
                return;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertAtEnd(10);
    // list.insertAtEnd(20);
    // list.insertAtPosition(0, 15);
    // list.insertAtHead(5);
    // list.deleteFromEnd();
    list.print();
    // list.deleteFromPosition(1);
    // list.updateByIndex(1,90);
    // list.updateByValue(5, 6);
    list.deleteFromEnd();
    list.print();
}