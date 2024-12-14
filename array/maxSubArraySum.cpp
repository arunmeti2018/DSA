#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force Approach (O(n^2))
int maxSubarraySumBruteForce(const vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// Kadane's Algorithm (O(n))
int maxSubarraySumKadane(const vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

// Driver Code
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Brute Force Approach
    int resultBruteForce = maxSubarraySumBruteForce(arr);
    cout << "Maximum Subarray Sum (Brute Force): " << resultBruteForce << endl;

    // Kadane's Algorithm
    int resultKadane = maxSubarraySumKadane(arr);
    cout << "Maximum Subarray Sum (Kadane's Algorithm): " << resultKadane << endl;

    return 0;
}
