#include <iostream>
#include <vector>
#include <algorithm> // For reverse function

using namespace std;
// brute force
// 1st Approach (Using rotation, O(d*n) time)
void rotateArrUsingRotation(vector<int> &arr, int d)
{
    int n = arr.size();
    for (int i = 0; i < d; i++)
    {
        int curr = arr[0];
        int j = 0;
        while (j < n - 1)
        {
            arr[j] = arr[j + 1];
            j++;
        }
        arr[n - 1] = curr;
    }
}

// 2nd Approach (Using extra space, O(n) time)
void rotateArrUsingExtraSpace(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle cases where d > n
    while (d > n - 1)
    {
        d = d - n;
    }

    vector<int> ans;
    ans.insert(ans.end(), arr.begin() + d, arr.end());
    ans.insert(ans.end(), arr.begin(), arr.begin() + d);
    arr = ans;
}

// optimized
// 3rd Approach (Using reversal, O(n) time)
void rotateArrUsingReversal(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle cases where d > n
    d = d % n;

    // Reverse the first d elements
    int i = 0, j = d - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }

    // Reverse the remaining elements
    i = d;
    j = n - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }

    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}

int main()
{
    // Test the three approaches
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int d = 2;

    // 1st Approach (Using extra space)
    vector<int> arrCopy1 = arr1; // Copy the original array to not overwrite the result
    rotateArrUsingExtraSpace(arrCopy1, d);
    cout << "1st Approach (Using extra space): ";
    for (int x : arrCopy1)
    {
        cout << x << " ";
    }
    cout << endl;

    // 2nd Approach (Using rotation)
    vector<int> arrCopy2 = arr1; // Copy the original array to not overwrite the result
    rotateArrUsingRotation(arrCopy2, d);
    cout << "2nd Approach (Using rotation): ";
    for (int x : arrCopy2)
    {
        cout << x << " ";
    }
    cout << endl;

    // 3rd Approach (Using reversal)
    vector<int> arrCopy3 = arr1; // Copy the original array to not overwrite the result
    rotateArrUsingReversal(arrCopy3, d);
    cout << "3rd Approach (Using reversal): ";
    for (int x : arrCopy3)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
