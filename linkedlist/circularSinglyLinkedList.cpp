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
class CircularSingularLinkedList
{
private:
    Node *head;

public:
    CircularSingularLinkedList()
    {
        this->head = nullptr;
    }
    ~CircularSingularLinkedList()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *current = head->next;
        while (current != head)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    void insertAtEnd(int value)
    {
        if (head == nullptr)
        {
            insertAtHead(value);
            return;
        }
        Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        Node *newNode = new Node(value);
        current->next = newNode;
        newNode->next = head;
    }

    void insertAtMiddle(int value)
    {
        if (head == nullptr)
        {
            insertAtHead(value);
            return;
        }

        Node *slow = head;
        Node *fast = head;
        // Node* temp = head;
        while (fast->next != head && fast->next->next != head)
        {
            // if(temp != slow){
            //     temp = temp -> next;
            // }
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *newNode = new Node(value);
        Node *nextNode = slow->next;
        slow->next = newNode;
        newNode->next = nextNode;
    }

    void insertAtPosition(int pos, int value)
    {
        if (pos < 1)
        {
            cout << "Position is out of bound" << endl;
            return;
        }
        if (pos == 1)
        {
            insertAtHead(value);
            return;
        }
        Node *tail = head;
        int count = 1;
        while (tail->next != head)
        {
            tail = tail->next;
            count++;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != tail; i++)
        {
            temp = temp->next;
        }

        if (pos == count + 1)
        {
            insertAtEnd(value);
            return;
        }
        if (pos > count + 1)
        {
            cout << "Position is out of bounds" << endl;
            return;
        }
        Node *newNode = new Node(value);
        Node *nextNode = temp->next;
        newNode->next = nextNode;
        temp->next = newNode;
    }

    void updateByPos(int pos, int value)
    {
        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node *temp = head;
        if (pos == 1)
        {
            temp->data = value;
            return;
        }
        int i = 1;
        do
        {
            i++;
            temp = temp->next;
        } while (temp != head && i < pos);
        if (temp == head)
        {
            cout << "Position not found" << endl;
            return;
        }
        temp->data = value;
    }

    void updateByValue(int oldVal, int newVal)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->data == oldVal)
            {
                temp->data = newVal;

                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Value not found" << endl;
    }

    void updateByIndex(int index, int value)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }

        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;

        if (index == 0)
        {
            temp->data = value;
            return;
        }
        int i = 0;
        do
        {
            if (i == index)
            {
                temp->data = value;

                return;
            }
            temp = temp->next;
            i++;
        } while (temp != head);
    }

    void deleteByPos(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            Node *lastNode = head;
            while (lastNode->next != head)
            {
                lastNode = lastNode->next;
            }
            Node *temp = head;
            if (temp->next == head)
            {
                head = nullptr;
                delete temp;
                return;
            }
            head = head->next;
            lastNode->next = head;
            delete temp;

            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            cout << "Position not found" << endl;
            return;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
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
            Node* lastNode = head;
            while(lastNode -> next != head){
                lastNode = lastNode -> next;
            }
            Node* temp = head;
            if(temp -> next == head){
                delete temp;
                head = nullptr;
                return;
            }
            head = head -> next;
            lastNode -> next = head;
            delete temp;
            return;
        }
        Node* temp = head;
        
        do
        {
            if(temp -> next -> data == value){
                Node* delteNode = temp -> next;
        temp -> next = delteNode -> next;
        delete delteNode;
        return;
            }
            temp = temp -> next;
        } while (temp -> next != head);
       
    cout << "Value not found" << endl;
    }

    Node* reverseCircularLinkedList(){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return nullptr;
        }
        Node* lastNode = head;
        while(lastNode -> next != head){
            lastNode = lastNode -> next;
        }
        Node* prev = lastNode;
        Node* current = head;
        Node* nextNode = nullptr;
        do
        {
            nextNode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);
        return prev;
        
    }

    void printNode()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != head)
            {
                cout << " -> ";
            }
        } while (temp != head);
        cout<<endl;
    }

    void printReverseLinkedList(Node* newHead){
        Node* temp = newHead;
        do
        {
            cout<<temp -> data;
            if(temp -> next != newHead){
                cout<<"->";
            }
            temp = temp -> next;
        } while (temp != newHead);
        cout<<endl;
    }
};
int main()
{
    CircularSingularLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(120);
    list.insertAtHead(120);
    list.insertAtEnd(800);
    list.insertAtEnd(800);
    list.insertAtEnd(800);
    list.insertAtEnd(800);
    list.insertAtMiddle(102);
    list.insertAtPosition(9, 1);
    list.updateByPos(83, 100);
    // list.updateByValue(122342,20); 
    list.updateByIndex(0, 2000);
    // list.deleteByPos(91);
    list.deleteByValue(2000);
    list.printNode();
    Node* temp = list.reverseCircularLinkedList();
    list.printReverseLinkedList(temp);
    return 0;
}
