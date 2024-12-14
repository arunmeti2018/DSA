#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force Approach (O(n^2))
// This method computes the maximum subarray sum by checking every possible subarray.
// It uses a nested loop where:
// - Outer loop selects the starting index of the subarray.
// - Inner loop iterates through the remaining elements to calculate the sum of the subarray.
int maxSubarraySumBruteForce(const vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer value.

    for (int i = 0; i < n; i++)
    {
        int currSum = 0; // Variable to store the current subarray sum starting at index i.
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];             // Add the current element to the subarray sum.
            maxSum = max(maxSum, currSum); // Update maxSum if the current subarray sum is larger.
        }
    }

    return maxSum;
}

// Kadane's Algorithm (O(n))
// This method finds the maximum subarray sum in a single pass through the array.
// It maintains a running sum of the current subarray (`currSum`) and resets it to 0 if it becomes negative.
int maxSubarraySumKadane(const vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer value.
    int currSum = 0;      // Variable to store the running sum of the current subarray.

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];             // Add the current element to the running sum.
        maxSum = max(maxSum, currSum); // Update maxSum if the running sum is larger.
        if (currSum < 0)
        {
            currSum = 0; // Reset currSum to 0 if it becomes negative, as starting a new subarray is better.
        }
    }

    return maxSum;
}

// Driver Code
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Input array.

    cout << "Array: ";
    for (int num : arr)
    {
        cout << num << " "; // Print the array elements.
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
