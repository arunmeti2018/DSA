#include <iostream>
using namespace std;

int main()
{
    int n = 4;
//   reverse trangle 
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n-i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }




 
    return 0;
}