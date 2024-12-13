#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// O(N^2)
// Function to find max profit using brute force approach
int maxProfitBruteForce(const vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

// O(n)
// Function to find max profit using single pass method
int maxProfitSinglePass(const vector<int> &prices)
{
    int buy = 0;
    int n = prices.size();
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[buy])
            maxProfit = max(maxProfit, prices[i] - prices[buy]);
        else
            buy = i;
    }

    return maxProfit;
}

// Driver code
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Stock Prices: ";
    for (int price : prices)
    {
        cout << price << " ";
    }
    cout << endl;

    // Using Brute Force
    int profitBruteForce = maxProfitBruteForce(prices);
    cout << "Maximum Profit (Brute Force): " << profitBruteForce << endl;

    // Using Single Pass
    int profitSinglePass = maxProfitSinglePass(prices);
    cout << "Maximum Profit (Single Pass): " << profitSinglePass << endl;

    return 0;
}
