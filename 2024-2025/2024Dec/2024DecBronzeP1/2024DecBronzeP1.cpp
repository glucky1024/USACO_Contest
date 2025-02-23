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
#include <set>
#include <map>

using namespace std;
typedef long long int lli;

bool ReadInFile(const string& sFile, std::vector<unsigned int>& vec)
{
    vec.clear();
    //fstream in;
    //in.open(sFile, ios::in);
    //if (!in.is_open())
    //{
    //    cout << "Error: cannot open input file." << endl;
    //    return false;
    //}

    unsigned int t = 0, n = 0;
    cin >> t;
    for (unsigned int i = 0; i < t; ++i) {
        cin >> n;
        //vec.push_back(n);

        long long cnt = 0;
        int max = 0;
        if (n > 45)
        {
            if (n < 49)
            {
                cnt += n - 45 + 1;
            }

            else {
                cnt += 5;
                max = 1;
            }

        }
        if (n > 445)
        {
            if (n < 499)
            {
                cnt += (n - 445 + 1);
            }

            else {
                cnt += 55;
                max = 2;
            }

        }
        if (n > 4445)
        {
            if (n < 4999)
            {
                cnt += (n - 4445 + 1);
            }

            else {
                cnt += 555;
                max = 3;
            }

        }
        if (n > 44445)
        {
            if (n < 49999)
            {
                cnt += n - 44445 + 1;
            }

            else {
                cnt += 5555;
            }

        }
        if (n > 444445)
        {
            if (n < 499999)
            {
                cnt += n - 444445 + 1;
            }

            else {
                cnt += 55555;
                max = 5;
            }

        }
        if (n > 4444445)
        {
            if (n < 4999999)
            {
                cnt += n - 4444445 + 1;
            }

            else {
                cnt += 555555;
                max = 6;
            }

        }
        if (n > 44444445)
        {
            if (n < 49999999)
            {
                cnt += n - 44444445 + 1;
            }
            else {
                cnt += 5555555;
                max = 7;
            }

        }
        if (n > 444444445)
        {
            if (n < 499999999)
            {
                cnt += n - 444444445 + 1;
            }
            else
            {
                cnt += 55555555;
                max = 8;
            }

        }
        if (n > 4444444445)
        {
            if (n < 4999999999)
            {
                cnt += n - 4444444445 + 1;
            }
            else {
                cnt += 555555555;
                max = 9;
            }

        }

        cout << cnt << endl;
    }

    return true;
}

void Print()
{


    cout << endl;
}

bool ReadInCout(std::vector<unsigned int>& vec)
{
    ios::sync_with_stdio(0); cin.tie(0);

    unsigned int t = 0, n = 0;
    cin >> t;
    for (unsigned int i = 0; i < t; ++i) {
        cin >> n;
        vec.push_back(n);
    }

    return true;
}

unsigned int Find_b(unsigned int N)
{
    unsigned int count = 0;
    while (true)
    {
        N = (unsigned int)N / 10;
        if (N < 1)
            break;
        count++;
    }

    return count + 1;
}

unsigned int RoundChain(unsigned int a, unsigned int b)
{
    for (unsigned int i = 0; i < b; ++i)
    {
        unsigned int nearest = std::pow(10, i + 1);
        unsigned int nthDigit = (a * 10 / nearest) % 10;
        if (nthDigit >= 5)
        {
            a += nearest;
        }
    }

    unsigned int nearest = std::pow(10, b);
    unsigned int res = (round)(a / nearest) * nearest;

    return res;
}

unsigned int RoundGeneral(unsigned int a, unsigned int b)
{
    unsigned int nearest = std::pow(10, b);
    unsigned int nthDigit = (a * 10 / nearest) % 10;

    if (nthDigit >= 5)
    {
        a += nearest;
    }

    nthDigit = a / nearest;
    unsigned int res = nthDigit * nearest;

    return res;
}

unsigned int FindP(unsigned int N)
{
    unsigned int count = 0;
    while (true)
    {
        N = (unsigned int)N / 10;
        if (N < 1)
            break;
        count++;
    }

    return count;
}

unsigned int findLargestN(const std::vector<unsigned int>& vec)
{
    unsigned int res = 0;
    for (unsigned int ui : vec)
    {
        res = ui > res ? ui : res;
    }
    return res;
}

int main()
{
    std::vector<unsigned int> vec;

    bool bOk = ReadInFile("1.in", vec);

    //ReadInCout(vec);

    //unsigned int LargestN = findLargestN(vec);
    //std::vector<bool> vecDiffs;
    //for (unsigned int j = 1; j <= LargestN; j++)
    //{
    //    unsigned int b = Find_b(j);
    //    unsigned int res_gen = RoundGeneral(j, b);
    //    unsigned int res_chain = RoundChain(j, b);
    //    if (res_gen != res_chain)
    //    {
    //        vecDiffs.push_back(true);
    //    }
    //    else
    //    {
    //        vecDiffs.push_back(false);
    //    }
    //}

    //for (unsigned int i = 0; i < vec.size(); ++i)
    //{
    //    unsigned int N = vec[i];

    //    //unsigned int b = Find_b(N);
    //    //unsigned int res_gen = RoundGeneral(N, b);
    //    //unsigned int res_chain = RoundChain(N, b);
    //    //cout << N << ", " << res_gen << ", " << res_chain << endl;
    //    int diff = 0;
    //    for (unsigned int j = 1; j <= N; j++)
    //    {
    //        if (vecDiffs[j-1])
    //            diff++;
    //    }
    //    cout << diff << endl;
    //}


    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        unsigned int N = vec[i];
        int diff = 0;
        for (unsigned int j = 2; j <= N; j++)
        {
            unsigned int b = Find_b(j);
            unsigned int res_gen = RoundGeneral(j, b);
            unsigned int res_chain = RoundChain(j, b);
            if (res_gen != res_chain)
            {
                diff++;
            }
        }
        cout << diff << endl;
    }

    return 0;
}
