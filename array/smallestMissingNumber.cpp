#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// O(n^2)
// Brute Force Approach: Check for each number from 1 to n if it is in the array
int missingNumberBruteForce(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return i;
    }
    return n + 1;
}

// time - O(n) and space O(n)
// Approach 2: Using a map (extra space)
int missingNumberUsingMap(vector<int> &arr)
{
    int n = arr.size();
    vector<int> map(n + 1, 0);

    // Mark the presence of numbers within range [1, n]
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            map[arr[i]]++;
        }
    }

    // Find the first missing positive number
    for (int i = 1; i < map.size(); i++)
    {
        if (map[i] == 0)
        {
            return i;
        }
    }

    // If all numbers from 1 to n are present
    return n + 1;
}

// time O(n)
// Approach 3: Using modified array (no extra space)
int missingNumberModifiedArray(vector<int> &arr)
{
    int n = arr.size();
    int mx = INT_MIN;

    // Step 1: Replace non-positive numbers with 0 and find the maximum number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
            arr[i] = 0;
        mx = max(mx, arr[i]);
    }
    mx = mx + 1;

    // Step 2: Use modulo to mark the elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            int ind = arr[i] % mx - 1;
            if (ind < n && ind >= 0)
            {
                arr[ind] += mx;
            }
        }
    }

    // Step 3: Find the first missing positive number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mx)
        {
            return i + 1;
        }
    }

    // If all positive numbers from 1 to n are present
    return n + 1;
}

int main()
{
    // Driver code to test all three approaches
    vector<int> arr1 = {3, 4, -1, 1};

    // Test Brute Force Approach
    cout << "Brute Force Approach - Missing number in arr1: "
         << missingNumberBruteForce(arr1) << endl; // Expected output: 2

    // Test Map-based Approach
    cout << "Approach 2 (Using map) - Missing number in arr1: "
         << missingNumberUsingMap(arr1) << endl; // Expected output: 2

    // Test Modified Array Approach
    cout << "Approach 3 (Using modified array) - Missing number in arr1: "
         << missingNumberModifiedArray(arr1) << endl; // Expected output: 2
    return 0;
}
