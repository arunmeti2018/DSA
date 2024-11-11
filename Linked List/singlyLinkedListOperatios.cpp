#include <iostream>
#include <vector>
#include <string>
using namespace std;

//defining a node sructure 
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        // create a temp node;
        this->data = data;
        this->next = NULL;
    }
};

// inserting new node at begining 
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);

    temp->next = head;
    head = temp;
}

// priniting the linked list 
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
    cout << endl;
}

// inserting a new node at end 
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}  

// inserting new node at specific position 
void insertAtPosition(node *tail, node *&head, int pos, int d)
{
    node *temp = head;
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting a node from a specific position 
void deleteAtPosition(node *&head, int pos)
{
    node *prev = NULL;
    node *curr = head;
    int count = 1;
    if (pos == 1)
    {
        prev = head;
        head = head->next;
        prev->next = NULL;
        delete prev;
        return;
    }
    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// checking whether given linked list is palindrome or not
bool checkPalindrome(node *head)
{

    node *temp = head;
    vector<int> v;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int r = v.size() - 1;
    int l = 0;
    while (l < r)
    {
        if (v[l] != v[r])
        {
            return false;
        }
        else
        {
            l++;
            r--;
        }
    }
    return true;
}
int main()
{
    node *node1 = new node(12);
    node *head = node1;
    node *tail = node1;
    print(head);
    insertAtTail(tail, 1);
    insertAtTail(tail, 12);
    insertAtTail(tail, 12);
    insertAtTail(tail, 1);
    insertAtTail(tail, 12);
    print(head);
    // insertAtTail(tail, 15);
    // print(head);
    // insertAtPosition(tail, head, 4, 22);
    // print(head);
    // deleteAtPosition(head, 1);
    // print(head);
 

    return 0;
}