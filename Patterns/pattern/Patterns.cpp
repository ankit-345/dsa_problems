#include <bits/stdc++.h>
using namespace std;

void hollow_rectangle(int n)
{

    //    *****
    //    *   *
    //    *   *
    //    *   *
    //    *****

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void inverted_half_pyramid(int n)
{

    //    * * * * *
    //    * * * *
    //    * * *
    //    * *
    //    *
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void half_pyramid_rotation(int n)
{

    //         *
    //       * *
    //     * * *
    //   * * * *
    // * * * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= (n - i))
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void half_pyramid_Numbers(int n)
{
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void floyd_triangle(int n)
{

    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

// BUTTERFLY PATTERN

void butterfly(int n)
{

    // upper part.
    // *                 *
    // * *             * *
    // * * *         * * *
    // * * * *     * * * *
    // * * * * * * * * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }

        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << " "
                 << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    // Lower part.
    // * * * * * * * * * *
    // * * * *     * * * *
    // * * *         * * *
    // * *             * *
    // *                 *
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }

        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << " "
                 << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    hollow_rectangle(n);
    inverted_half_pyramid(n);
    half_pyramid_rotation(n);
    half_pyramid_Numbers(n);
    floyd_triangle(n);
    butterfly(n);
    return 0;
}