#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insertIntoHeap(int);
    void deleteFromHeap();
    void print();
};
void heap::insertIntoHeap(int val)
{
    size++;
    int index = size;
    arr[index] = val;
    while (index > 1)
    {
        int parent = index / 2;
        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
            return;
    }
}
void heap::deleteFromHeap()
{

    arr[1] = arr[size];
    size--;
    int i = 1;

    while (i < size)
    {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        if (leftChild < size && arr[leftChild] > arr[i])
        {
            swap(arr[leftChild], arr[i]);
            i = leftChild;
        }
        else if (rightChild < size && arr[rightChild] > arr[i])
        {
            swap(arr[rightChild], arr[i]);
            i = rightChild;
        }
        else
            return;
    }
}

void heap::print()
{

    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    heap h;
    h.insertIntoHeap(55);
    h.insertIntoHeap(54);
    h.insertIntoHeap(53);
    h.insertIntoHeap(50);
    h.insertIntoHeap(52);
    // h.insertIntoHeap(25);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}