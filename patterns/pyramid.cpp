#include <iostream>
using namespace std;

int main()
{
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        //    spaces
        for (int j = 0; j < 2 * (n - i); j++) // we need 2(n-row number )spaces to print correctly
                                              // printing n-i-1 is also wroks bu for higher n value it dosnt work
        {
            cout << " ";
        }
        // left triangle
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    //        1
    //      1 2 1
    //    1 2 3 2 1
    //  1 2 3 4 3 2 1

    return 0;
}