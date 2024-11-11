#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class node
{
public:
    int data;   // Data stored in the node
    node *next; // Pointer to the next node in the linked list

    // Constructor to initialize a new node with given data
    node(int data)
    {
        this->data = data; // Set the node's data
        this->next = NULL; // Initialize the next pointer to NULL
    }

    // Destructor for the node class
    // This destructor is simplified and does not attempt to delete `next`
    // as it could lead to double deletion. The linked list should be deleted
    // externally, not from within the destructor.
    ~node()
    {
        // No need to delete `next` here; memory management should be handled outside
    }
};

// Function to insert a new node at the head of the linked list
void insertAtHead(node *&head, int d)
{
    // Create a new node with the given data
    node *temp = new node(d);

    // Set the new node's next to the current head
    temp->next = head;

    // Update the head to point to the new node
    head = temp;
}

// Function to insert a new node at the tail of the linked list
void insertAtTail(node *&tail, int d)
{
    // Create a new node with the given data
    node *temp = new node(d);

    // Link the current tail node to the new node
    tail->next = temp;

    // Update the tail to be the new node
    tail = temp;
}

// Function to print the linked list starting from the head
void print(node *&head)
{
    node *temp = head; // Start from the head

    // Traverse the list and print each node's data
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // Move to the next node
    }
    cout << endl; // Print a newline after printing the list
}

// Function to find the middle node of the linked list
node *middle(node *head)
{
    // Initialize two pointers - slow and fast
    node *fast = head->next; // Fast pointer starts at the second node
    node *slow = head;       // Slow pointer starts at the head

    // Traverse the list with the fast and slow pointers
    while (fast != NULL)
    {
        fast = fast->next; // Move fast by one node
        if (fast != NULL)
        {
            fast = fast->next; // Move fast by another node
        }
        slow = slow->next; // Move slow by one node
    }
    // When fast reaches the end, slow is at the middle node
    return slow;
}

// Function to detect a loop in the linked list
// If a loop exists, it returns the node where the loop starts
node *detectLoop(node *head)
{
    if (head == NULL)
        return NULL; // Return NULL if the list is empty

    // Initialize two pointers - slow and fast
    node *slow = head;
    node *fast = head;

    // Traverse the list with fast and slow pointers
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next; // Move fast by two steps
        slow = slow->next;       // Move slow by one step

        // If slow and fast meet, a loop is detected
        if (slow == fast)
        {
            slow = head; // Reset slow to the head

            // Move both pointers one step at a time to find the loop's starting node
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return the start of the loop
        }
    }

    return NULL; // Return NULL if no loop is detected
}

// Main function to demonstrate linked list operations
int main()
{
    // Create the first node with data 10
    node *node1 = new node(10);

    // Initialize head and tail to the first node
    node *head = node1;
    node *tail = node1;

    // Print the current linked list
    print(head);

    // Insert nodes at the tail and print after each insertion
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 155);
    print(head);

    // Detect a loop in the linked list
    node *loopNode = detectLoop(head);
    if (loopNode)
    {
        cout << "Loop detected at node with data: " << loopNode->data << endl;
    }
    else
    {
        cout << "No loop detected" << endl;
    }

    // Find and print the middle node of the linked list
    node *mid = middle(head);
    if (mid)
    {
        cout << "Middle node data: " << mid->data << endl;
    }

    return 0;
}
