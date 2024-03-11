#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <stack>

using namespace std;

bool ReadInFile(const string& sFile, vector<bool>& infects)
{



    return true;
}

bool ReadInCout(vector<bool>& infects)
{
    ios::sync_with_stdio(0); cin.tie(0);


    return true;
}

void Print(const vector<bool>& infects)
{
}

void WriteOut(const string& sFile, int)
{
    //cout <<  << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

bool isPalindrome(long num)
{
    long digit = 0, rev = 0;
    long n = num;
    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);

    return n == rev;
}

int main()
{
    int test = 0;

    //fstream in;
    //in.open("../P1.in", ios::in);
    //if (!in.is_open()) {
    //    cout << "Error: cannot open input file." << endl;
    //    return false;
    //}
    //in >> test;

    cin >> test;

    for (int t = 0; t < test; t++)
    {
        long long S = 0;

        //in >> S;
        cin >> S;

        if (S % 10 == 0)
        {
            cout << "E" << endl;
        }

        else
        {
            cout << "B" << endl;
        }


        //if (isPalindrome(S))
        //{
        //    cout << "B" << endl;
        //    continue;
        //}
        //else if (S == 10)
        //{
        //    cout << "E" << endl;
        //    continue;
        //}

        //bool bFound = false;
        //while (S > 9)
        //{
        //    // find x
        //    long x = S - 10;
        //    while (x > 0)
        //    {
        //        if (isPalindrome(x))
        //            break;
        //        x--;
        //    }

        //    S -= x;
        //    if (!isPalindrome(S) && isPalindrome(S - 1)) {
        //        cout << "B" << endl;
        //        bFound = true;
        //        break;
        //    }
        //}

        //if (!bFound)
        //    cout << "E" << endl;

        //while (true)
        //{
        //    //B turn

        //    if (isPalindrome(S))
        //    {
        //        cout << "B" << endl;
        //        break;
        //    }         

        //    int dist = S - 10;

        //    if (dist != 0 && isPalindrome(dist))
        //    {
        //        cout << "B" << endl;
        //        break;
        //    }

        //    else
        //    {
        //        int tempS = S - 1;
        //        bool found = false;

        //        while (tempS != 0)
        //        {
        //            if (!isPalindrome(tempS) )
        //            {
        //                if (isPalindrome(S - tempS))
        //                {
        //                    found = true;
        //                    break;
        //                }
        //            }
        //            tempS--;
        //        }

        //        if (!found)
        //        {
        //            cout << "E" << endl;
        //            break;
        //        }

        //        S = tempS;
        //    }

        //    //E turn
        //    if (isPalindrome(S))
        //    {
        //        cout << "E" << endl;
        //        break;
        //    }

        //    int dist2 = S - 10;

        //    if (dist2 != 0 && isPalindrome(dist2))
        //    {
        //        cout << "E" << endl;
        //        break;
        //    }

        //    else
        //    {
        //        int tempS = S - 1;
        //        bool found = false;

        //        while (tempS != 0)
        //        {
        //            if (!isPalindrome(tempS) )
        //            {
        //                if (isPalindrome(S - tempS))
        //                {         
        //                    found = true;
        //                    break;
        //                }
        //            }
        //            tempS--;
        //        }

        //        if (!found)
        //        {
        //            cout << "B" << endl;
        //            break;
        //        }

        //        S = tempS;
        //    }
        //}
    }
}