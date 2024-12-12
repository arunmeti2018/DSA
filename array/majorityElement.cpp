#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//  time complexity O(n) space complexity O(n)
// Approach 1: Using Unordered Map (Hashing)
vector<int> findMajorityHashing(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> freqMap;
    vector<int> ans;

    // Count frequencies
    for (int num : arr)
    {
        freqMap[num]++;
    }

    // Check for elements with frequency > n/3
    for (auto pair : freqMap)
    {
        if (pair.second > n / 3)
        {
            ans.push_back(pair.first);
        }
    }

    sort(ans.begin(), ans.end()); // Sorting the result for consistent output
    return ans;
}

// Approach 2: Using Boyer-Moore Voting Algorithm
// time complexity O(n) space complexity O(1)
vector<int> findMajorityVoting(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int candidate1 = 0, candidate2 = 1; // Initialize candidates to different values
    int count1 = 0, count2 = 0;

    // Phase 1: Find potential candidates
    for (int num : arr)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Phase 2: Validate candidates
    count1 = count2 = 0;
    for (int num : arr)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
    }

    // Ensure the smaller candidate is added first
    if (candidate1 > candidate2)
    {
        swap(candidate1, candidate2);
        swap(count1, count2);
    }

    if (count1 > n / 3)
        ans.push_back(candidate1);
    if (count2 > n / 3)
        ans.push_back(candidate2);

    return ans;
}

// Approach 3: Sorting and Counting
// time complexity O(nlogn) space complexity O(1)
vector<int> findMajoritySorting(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;

    sort(arr.begin(), arr.end());

    // Traverse sorted array to count frequencies
    for (int i = 0; i < n;)
    {
        int count = 1;
        while (i + count < n && arr[i + count] == arr[i])
        {
            count++;
        }

        if (count > n / 3)
        {
            ans.push_back(arr[i]);
        }

        i += count; // Move to the next distinct element
    }

    return ans;
}

// Driver Code
int main()
{
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};

    // Call each function and display results
    vector<int> resultHashing = findMajorityHashing(arr);
    vector<int> resultVoting = findMajorityVoting(arr);
    vector<int> resultSorting = findMajoritySorting(arr);

    // Print results
    cout << "Using Hashing: ";
    for (int num : resultHashing)
        cout << num << " ";
    cout << endl;

    cout << "Using Boyer-Moore Voting: ";
    for (int num : resultVoting)
        cout << num << " ";
    cout << endl;

    cout << "Using Sorting: ";
    for (int num : resultSorting)
        cout << num << " ";
    cout << endl;

    return 0;
}
