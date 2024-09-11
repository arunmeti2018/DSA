#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    // right angle triangle
    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }




    for (int i = 0; i < n; i++)
    { // n-i spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // i stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << j << " ";
        }

       

        cout << endl;
    }
    return 0;
}