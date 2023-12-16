/*
PROG: cow college
LANG: C++11
*/

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

bool ReadInFile(const string& sFile, vector<long>& cowMoney)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    long nCows = 0;
    in_file >> nCows;
    cowMoney.clear();
    for (int i = 0; i < nCows; i++)
    {
        long m = 0;
        in_file >> m;
        cowMoney.push_back(m);
    }

    return true;
}

bool ReadInCout(vector<long>& cowMoney)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows = 0;
    cin >> nCows;
    cowMoney.clear();
    for (int i = 0; i < nCows; i++)
    {
        long m = 0;
        cin >> m;
        cowMoney.push_back(m);
    }

    return true;
}

void Print(const int& nCows, const vector<int>& cowMoney)
{
    cout << nCows << endl;
    for (int i = 0; i < nCows; i++)
    {
        cout << cowMoney[i] << " ";
    }
    cout << endl;
}

void WriteOut(const string& sFile, int a, int d)
{
    cout << a << " " << d << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main2()
{
    // Step1: read
    vector<long> cowMoney;
    //bool bOk = ReadInFile("prob1_bronze_dec22/1.in", cowMoney);
    bool bOk = ReadInCout(cowMoney);
    if (!bOk) { return 0; }
    //Print(nCows, cowMoney);

    // Step2: get min/max, range
    long maxPay = -INT_MAX, minPay = INT_MAX;
    for (int m : cowMoney) {
        if (m > maxPay)
            maxPay = m;
        if (m < minPay)
            minPay = m;
    }

    // Step3: sort
    sort(cowMoney.begin(), cowMoney.end());

    // Step4: solve
    long amount = 0;
    long dollar = 0;
    int nCows = cowMoney.size();
    //for (int i = 0; i < cowMoney.size(); i++)
    for (int iPay = minPay; iPay <= maxPay; iPay++)
    {
        //int iPay = cowMoney[i];
        long localPay = 0;
        for (int j = 0; j < nCows; j++)
        {
            if (cowMoney[j] >= iPay) {
                localPay += iPay;
            }
        }

        if (localPay > amount) {
            amount = localPay;
            dollar = iPay;
        }
    }

    WriteOut("collegeCows.out", amount, dollar);

    return 0;
}


int main() {
    int n; cin >> n;
    std::vector<long long> maxTuition(n);
    for (int i = 0; i < n; i++) {
        cin >> maxTuition[i];
    }

    sort(maxTuition.begin(), maxTuition.end());

    long long maxMoney = 0, bestTuition = 0;
    int numberOfCowsWillingToAttend = n;
    for (int i = 0; i < n; i++) 
    {
        long long setTuitionToIthCowsetTuitionToIthCow = maxTuition[i] * numberOfCowsWillingToAttend;

        //if (setTuitionToIthCow > maxMoney) {
        //    maxMoney = setTuitionToIthCow;
        //    bestTuition = maxTuition[i];
        //}

        numberOfCowsWillingToAttend--; // The ith cow isn't willing to pay any more tuition
    }

    cout << maxMoney << " " << bestTuition << endl;

    return 0;
}