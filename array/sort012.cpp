#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach: Counting zeros, ones, and twos
void sort012BruteForce(vector<int> &arr)
{
    int zero = 0, one = 0, two = 0;

    // Count occurrences of 0, 1, and 2
    for (int ele : arr)
    {
        if (ele == 0)
            zero++;
        else if (ele == 1)
            one++;
        else if (ele == 2)
            two++;
    }

    // Overwrite array based on counts
    int idx = 0;

    while (zero > 0)
    {
        arr[idx++] = 0;
        zero--;
    }
    while (one > 0)
    {
        arr[idx++] = 1;
        one--;
    }
    while (two > 0)
    {
        arr[idx++] = 2;
        two--;
    }
}

// Optimized Approach: Dutch National Flag Algorithm
void sort012Optimized(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Driver Code
int main()
{
    vector<int> arr1 = {0, 1, 2, 1, 0, 2, 1, 0, 2}; // Example input
    vector<int> arr2 = arr1;                        // Copy of the array for optimized approach

    cout << "Original Array: ";
    for (int ele : arr1)
        cout << ele << " ";
    cout << endl;

    // Brute Force
    sort012BruteForce(arr1);
    cout << "After Brute Force Sorting: ";
    for (int ele : arr1)
        cout << ele << " ";
    cout << endl;

    // Optimized Approach
    sort012Optimized(arr2);
    cout << "After Optimized Sorting: ";
    for (int ele : arr2)
        cout << ele << " ";
    cout << endl;

    return 0;
}
