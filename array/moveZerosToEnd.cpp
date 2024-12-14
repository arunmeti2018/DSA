#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using Extra Space
void pushZerosToEnd_ExtraSpace(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n, 0);
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[idx++] = arr[i];
        }
    }

    arr = temp;
}

// Approach 2: Using Two-Pointer Technique (In-place)
void pushZerosToEnd_TwoPointer(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Utility Function: Print Vector
void printVector(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    vector<int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

    cout << "Original Array: ";
    printVector(arr);

    // Using Extra Space Approach
    vector<int> arr1 = arr;
    pushZerosToEnd_ExtraSpace(arr1);
    cout << "After Moving Zeros (Extra Space): ";
    printVector(arr1);

    // Using Two-Pointer Approach
    vector<int> arr2 = arr;
    pushZerosToEnd_TwoPointer(arr2);
    cout << "After Moving Zeros (Two-Pointer): ";
    printVector(arr2);

    return 0;
}
