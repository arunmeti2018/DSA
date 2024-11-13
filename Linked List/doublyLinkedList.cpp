#include <iostream>
using namespace std;

// Node class for doubly linked list
class node
{
public:
    int data;
    node *prev; // Pointer to the previous node
    node *next; // Pointer to the next node

    // Constructor to initialize a new node
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor to delete a node and clean up memory
    ~node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << value << " deleted" << endl;
    }
};

// Function to insert a node at the head of the list
void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    { // If list is empty, initialize head and tail
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    { // Otherwise, insert new node before the current head
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Function to insert a node at the tail of the list
void insertAtTail(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    { // If list is empty, initialize head and tail
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    { // Otherwise, insert new node after the current tail
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Function to insert a node at a specific position in the list
void insertAtPosition(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    { // Insert at head if position is 1
        insertAtHead(head, tail, d);
        return;
    }

    int count = 1;
    node *temp = head;

    // Traverse to the node just before the desired position
    while (count < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    { // If position is beyond list end, insert at tail
        insertAtTail(head, tail, d);
        return;
    }

    // Insert node at the found position
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    if (temp->next != NULL)
    { // Update next node's `prev` if it exists
        temp->next->prev = nodetoinsert;
    }
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

// Function to print all nodes in the list
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    { // Traverse and print each node
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to calculate the length of the list
int length(node *&head)
{
    node *temp = head;
    int len = 0; // Initialize length counter to 0

    while (temp != NULL)
    { // Traverse list and increment length
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to delete a node at a specific position in the list
void deletePosition(node *&head, node *&tail, int pos)
{
    if (head == NULL)
        return; // If list is empty, do nothing

    node *curr = head;

    // If deleting the head node
    if (pos == 1)
    {
        head = curr->next; // Move head to the next node
        if (head != NULL)
        { // If list isn't empty after deletion
            head->prev = NULL;
        }
        curr->next = NULL;
        delete curr; // Delete old head
        return;
    }

    node *back = NULL;
    int count = 1;

    // Traverse to the node at the desired position
    while (count < pos && curr != NULL)
    {
        back = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL)
        return; // Position is out of bounds

    // If deleting the tail node
    if (curr->next == NULL)
    {
        back->next = NULL; // Update `back` to point to NULL as `curr` is last node
        tail = back;       // Update tail pointer
    }
    else
    {                            // If deleting a middle node
        back->next = curr->next; // Link `back` to node after `curr`
        curr->next->prev = back; // Update `prev` of next node
    }

    curr->prev = NULL;
    curr->next = NULL;
    delete curr; // Delete the node at the given position
}

int main()
{
    node *node1 = NULL;
    node *head = node1;
    node *tail = node1;

    print(head); // Print empty list (initially)

    // Insert nodes at the tail
    insertAtTail(head, tail, 1);
    print(head);
    insertAtTail(head, tail, 12);
    print(head);
    insertAtTail(head, tail, 16);
    print(head);
    insertAtTail(head, tail, 100);
    print(head);

    // Test deleting a node at position 4
    deletePosition(head, tail, 4);
    print(head);
    deletePosition(head, tail, 1);
    print(head);
    insertAtPosition(head, tail, 2, 20);
    print(head);

    // Display head, tail, and length of the list
    cout << "Head = " << head->data << "\nTail = " << tail->data << endl;
    cout << "Length is: " << length(head) << endl;

    return 0;
}
