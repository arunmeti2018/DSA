//       *
//      * *
//     *   *
//    *     *
//   *       *
//  *         *
// *           *
//  *         *
//   *       *
//    *     *
//     *   *
//      * *
//       *

/*
approach
first divide the pattern horizontally in two parts


      FOR UPPER
 part first print( n-row numer ) spaces
then a *
then(  2* row number -1 )   number of inner spaces which are odd numbers 1 2 3 5....
then print a * and a next line
** note that dont print the 2nd star for for first row

    FOR LOWER
    first print (row number +1) spaces
    then print  *
    then print  2* row number -1 star from last or
                   print  spaces fro 0- 2*i-5   where i = row number
    then print a * and next line

 ** note that dont print any ineer spaces for last row (n-1)



                                                                     *
                                                                    * *        upper part
                                                                   *   *
                                                                  *     *
                                                                -------------
                                                                   *   *
                                                                    * *         lower part
                                                                     *
*/
#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    // top part
    //       *
    //      * *
    //     *   *
    //    *     *
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << " ";
        }
        if (i != 0)
            cout << "*";
        cout << endl;
    }
    // bottom part
    //     *   *
    //      * *
    //       *
    //    *** right to left approach***
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - i - 1; j > 0; j--)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 2 * i - 1; j > 0; j--)
        {
            cout << " ";
        }
        if (i != 0)
        {
            cout << "*";
        }
        cout << endl;
    }

    //  **** left to right approach for bottom part***
    // for (int i = 0; i < n - 1; i++)
    // {
    //     // spaces
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << " ";
    //     }
    //     // star
    //     cout << "*";
    //     // inner spaces

    //     if (i != n - 2)
    //     {
    //         for (int j = 0; j < 2 * (n - 2 - i) - 1; j++)
    //         {
    //             cout << " ";
    //         }
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    //    *
    //   * *
    //  *   *
    // *     *
    //  *   *
    //   * *
    //    *

    return 0;
}