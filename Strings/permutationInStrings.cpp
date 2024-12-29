#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

// Approach 1: Brute Force
bool isFreqSame(int freq[], int windFreq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] != windFreq[i])
            return false;
    }
    return true;
}

bool checkInclusionBruteForce(string s1, string s2) {
    int n = s2.length();
    int m = s1.length();
    int freq[26] = {0};

    // Fill frequency array for string s1
    for (int i = 0; i < m; i++) {
        freq[s1[i] - 'a']++;
    }

    // Traverse s2 to check for matching permutations
    for (int i = 0; i <= n - m; i++) {
        int windFreq[26] = {0};

        // Build a frequency array for the current window in s2
        for (int j = i; j < i + m; j++) {
            windFreq[s2[j] - 'a']++;
        }

        // Check if the current window matches s1's frequency
        if (isFreqSame(freq, windFreq))
            return true;
    }
    return false;
}

// Approach 2: Optimized Sliding Window
bool checkInclusionSlidingWindow(string s1, string s2) {
    int n = s2.length();
    int m = s1.length();
    if (m > n) return false;

    vector<int> freq(26, 0), windFreq(26, 0);

    // Fill frequency array for s1 and the first window of s2
    for (int i = 0; i < m; i++) {
        freq[s1[i] - 'a']++;
        windFreq[s2[i] - 'a']++;
    }

    // Check the first window
    if (freq == windFreq) return true;

    // Slide the window over s2
    for (int i = m; i < n; i++) {
        windFreq[s2[i] - 'a']++;          // Add new character to the window
        windFreq[s2[i - m] - 'a']--;      // Remove the oldest character from the window

        if (freq == windFreq) return true; // Compare frequencies
    }

    return false;
}

// Approach 3: Using Sorting
bool checkInclusionSorting(string s1, string s2) {
    int n = s2.length();
    int m = s1.length();
    if (m > n) return false;

    // Sort s1 for comparison
    sort(s1.begin(), s1.end());

    // Traverse all substrings of s2 of length m
    for (int i = 0; i <= n - m; i++) {
        string sub = s2.substr(i, m);
        sort(sub.begin(), sub.end());

        if (sub == s1) return true;
    }

    return false;
}

// Driver code
int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    // Test Approach 1: Brute Force
    if (checkInclusionBruteForce(s1, s2)) {
        cout << "[Brute Force] Permutation of s1 is a substring of s2." << endl;
    } else {
        cout << "[Brute Force] Permutation of s1 is NOT a substring of s2." << endl;
    }

    // Test Approach 2: Sliding Window
    if (checkInclusionSlidingWindow(s1, s2)) {
        cout << "[Sliding Window] Permutation of s1 is a substring of s2." << endl;
    } else {
        cout << "[Sliding Window] Permutation of s1 is NOT a substring of s2." << endl;
    }

    // Test Approach 3: Sorting
    if (checkInclusionSorting(s1, s2)) {
        cout << "[Sorting] Permutation of s1 is a substring of s2." << endl;
    } else {
        cout << "[Sorting] Permutation of s1 is NOT a substring of s2." << endl;
    }

    return 0;
}
