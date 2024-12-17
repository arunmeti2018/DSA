#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach: Combine arrays, sort, and distribute back
void mergeBruteForce(vector<int> &a, vector<int> &b)
{
    vector<int> merged;
    merged.insert(merged.end(), a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());

    sort(merged.begin(), merged.end());

    // Put elements back into a and b
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        a[i] = merged[i];
    }
    for (int i = 0; i < b.size(); i++)
    {
        b[i] = merged[n + i];
    }
}

// Swap and Sort Approach: Swap large values in a with small in b, then sort
void mergeSwapAndSort(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }

    // Sort both arrays again
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// Utility function to print a vector
void printArray(const vector<int> &arr)
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
    // Test Case
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13, 18};

    // Print input arrays
    cout << "Original Arrays:\n";
    cout << "A: ";
    printArray(a);
    cout << "B: ";
    printArray(b);

    // Brute Force Approach
    vector<int> a1 = a, b1 = b; // Copy arrays
    mergeBruteForce(a1, b1);
    cout << "\nAfter Brute Force Merge:\n";
    cout << "A: ";
    printArray(a1);
    cout << "B: ";
    printArray(b1);

    // Swap and Sort Approach
    vector<int> a3 = a, b3 = b; // Copy arrays
    mergeSwapAndSort(a3, b3);
    cout << "\nAfter Swap and Sort Merge:\n";
    cout << "A: ";
    printArray(a3);
    cout << "B: ";
    printArray(b3);

    return 0;
}
