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

using namespace std;

bool ReadInFile(const string& sFile, vector<long long>& volumes, vector<long long>& amounts)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        int tempa; int tempb;
        in >> tempa>> tempb;
        volumes.push_back(tempa);
        amounts.push_back(tempb);
    }

    return true;
}

void Print(const vector<long long> volumes, const vector<long long> amounts)
{
    for (int i = 0; i < 3; i++)
    {
        cout << volumes[i] << " "  << amounts[i] << endl;
    }
}

bool WriteOut(const string& sFile, const long long a, const long long b, const long long c)
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    //
    ofstream out_file;
    out_file.open(sFile);
    out_file << a << endl;
    out_file << b << endl;
    out_file << c << endl;


    out_file.close();

    return true;
}

int main()
{
    vector<long long> volumes;
    vector<long long> amounts;

    bool bOk = ReadInFile("mixmilk.in", volumes, amounts);
    //Print(volumes, amounts);

    long long a = amounts[0];
    long long b = amounts[1];
    long long c = amounts[2];

    //code!

    for (int i = 0; i < 33; i++)
    {
        //pour a to b
        if ((a + b) <= volumes[1])
        {
            b += a;
            a = 0;
        }

        else
        {
            int temp = a - ((a + b) - volumes[1]);
            b += temp;
            a -= temp;
        }

        //pour b to c
        if ((b + c) <= volumes[2])
        {
            c += b;
            b = 0;
        }

        else
        {
            int temp = b - ((b + c) - volumes[2]);
            c += temp;
            b -= temp;
        }

        //pour c to a
        if ((c + a) <= volumes[0])
        {
            a += c;
            c = 0;
        }

        else
        {
            int temp = c - ((c + a) - volumes[0]);
            a += temp;
            c -= temp;
        }
    }

    if ((a + b) <= volumes[1])
    {
        b += a;
        a = 0;
    }

    else
    {
        int temp = a - ((a + b) - volumes[1]);
        b += temp;
        a -= temp;
    }

    WriteOut("mixmilk.out", a, b, c);
}