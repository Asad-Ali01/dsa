#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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
    Node *create()
    {
        cout << "Enter number of linked list: ";
        int length;
        cin >> length;
        Node *tail;

        for (int i = 0; i < length; i++)
        {
            Node *temp = new Node;
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> temp->data;
            temp->next = nullptr;
            if (head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        cout << "Linked list created successfully" << endl;
        return head;
    }
    // update
    Node *update(int oldVal, int newVal)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
        }
        bool found = false;
        Node *temp = head;
        // Check value exists or not
        while (temp != nullptr)
        {
            if (temp->data == oldVal)
            {
                temp->data = newVal;
                found = true;
                cout << "Value updaetd successfully" << endl;
                // break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << oldVal << " does not exist on Linked list" << endl;
        }
        return head;
    }
    // display
    void display(Node* head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << "-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // delete
    Node *deleteLinkedList(int delVal)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return 0;
        }

        bool found = false;
        while (head != nullptr && head->data == delVal)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            found = true;
        }

        Node *current = head;
        Node *prev = nullptr;
        // Delete node other thand starts
        while (current != nullptr)
        {
            if (current->data == delVal)
            {
                prev->next = current->next;
                Node *temp = current;
                current = current->next;
                found = true;
                delete temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        
        if (!found)
        {
            cout << delVal << " value not found in linked list" << endl;
        }else{
                cout<<delVal<<" deleted successfully"<<endl;

        }
        return head;
    }
    // Delete by position

    Node *deleteByPosition(int position){
        if(head == nullptr){
            cout<<"Linked list is empty"<<endl;
            return 0;
        }

        //is position is worng
        if(position<=0){
            cout<<"Invalid position"<<endl;
            return 0;
        }
        // if position is head
        if(position == 1){
            Node* temp = head;
            head = head -> next;
            delete temp;
            cout<<"Node deleted successfully"<<endl;
            return 0;
        }

        //finding element at given position
        Node* current = head;
        Node* prev = nullptr;
        for(int i = 1; i < position && current != nullptr;i++){
            prev = current;
            current = current -> next;
        }

        //Now we are sure either we iterated to full linked list and not found the position or we got the position
        if(current == nullptr){
             cout << "Position out of range" << endl;
             return 0;
        }
        prev -> next = current -> next;
        cout<<"Node deleted successfully"<<endl;
        delete current;
       return head;
    }

    //reversing singly linked list
    Node *reverseSinglyLinkedList(){
        //checking if linked list is empty
        if(head == nullptr){
            cout<<"Linekd list is empty"<<endl;
            return 0;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while(current != nullptr){
           next = current -> next;
           current -> next = prev;
           prev = current;
           current = next;
        }
        head = prev;
        return head;
    }
};

int main()
{
    SinglyLinkedList obj;
   Node *head1 = obj.create();
    obj.display(head1);
   Node* head2 = obj.deleteLinkedList(3);
    obj.display(head2);
    Node* head3 = obj.reverseSinglyLinkedList();
    obj.display(head3);
}