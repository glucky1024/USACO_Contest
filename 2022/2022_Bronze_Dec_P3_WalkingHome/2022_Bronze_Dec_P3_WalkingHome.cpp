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

bool ReadInFile(const string& sFile, int& length, int& changes, vector<int>& grid)
{





    return true;
}

bool ReadInCout(vector<int>& tempsWant, vector<int>& tempsNow)
{
    ios::sync_with_stdio(0); cin.tie(0);

    return true;
}

void Print(const vector<int> tempsWant, const vector<int> tempsNow)
{
}

//int main()
//{
//    int tests;
//    cin >> tests;
//
//    int length = 0; int changes = 0;
//    vector<string> grid;
//
//    for (int p = 0; p < tests; p++)
//    {
//        cin >> length >> changes;
//        for (int j = 0; j < length; j++)
//        {
//            string t;
//            cin >> t;
//            grid.push_back(t);
//        }
//
//        int ret = 0;
//
//        if (changes >= 1)
//        {
//            bool urcorner = true;
//            bool dlcorner = true;
//            for (int j = 0; j < length; j++) {
//                if (grid[0][j] == 'H' || grid[j][length - 1] == 'H') urcorner = false;
//                if (grid[j][0] == 'H' || grid[length - 1][j] == 'H') dlcorner = false;
//            }
//            ret += urcorner;
//            ret += dlcorner;
//        }
//
//        if (changes >= 2)
//        {
//            // use column j
//            for (int j = 1; j < length - 1; j++) {
//                bool valid = true;
//                for (int k = 0; k < length; k++) {
//                    if (grid[k][j] == 'H') valid = false;
//                    if (k < j && grid[0][k] == 'H') valid = false;
//                    if (k > j && grid[length - 1][k] == 'H') valid = false;
//                }
//                ret += valid;
//            }
//            // use row i
//            for (int k = 1; k < length - 1; k++) {
//                bool valid = true;
//                for (int j = 0; j < length; j++) {
//                    if (grid[k][j] == 'H') valid = false;
//                    if (j < k && grid[j][0] == 'H') valid = false;
//                    if (j > k && grid[j][length - 1] == 'H') valid = false;
//                }
//                ret += valid;
//            }
//
//            if (changes >= 3)
//            {
//                for (int i = 1; i < length - 1; i++) {
//                    for (int j = 1; j < length - 1; j++) {
//                        // RDRD
//                        bool valid = grid[i][j] == '.';
//                        for (int a = 0; a < length; a++) {
//                            if (a <= i && grid[a][j] == 'H') valid = false;
//                            if (a >= i && grid[a][length - 1] == 'H') valid = false;
//                            if (a <= j && grid[0][a] == 'H') valid = false;
//                            if (a >= j && grid[i][a] == 'H') valid = false;
//                        }
//                        ret += valid;
//                        valid = grid[i][j] == '.';
//                        // DRDR
//                        for (int a = 0; a < length; a++) {
//                            if (a <= i && grid[a][0] == 'H') valid = false;
//                            if (a >= i && grid[a][j] == 'H') valid = false;
//                            if (a <= j && grid[i][a] == 'H') valid = false;
//                            if (a >= j && grid[length - 1][a] == 'H') valid = false;
//                        }
//                        ret += valid;
//                    }
//                }
//            }
//        }
//
//        cout << ret << "\n";
//
//        //bool bOk = ReadInCout(tempsWant, tempsNow);
//        //if (!bOk) { return 0; }
//    }
//}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int ret = 0;
    if (k >= 1) {
        bool urcorner = true;
        bool dlcorner = true;
        for (int i = 0; i < n; i++) {
            if (g[0][i] == 'H' || g[i][n - 1] == 'H') urcorner = false;
            if (g[i][0] == 'H' || g[n - 1][i] == 'H') dlcorner = false;
        }
        ret += urcorner;
        ret += dlcorner;
    }
    if (k >= 2) {
        // use column j
        for (int j = 1; j < n - 1; j++) {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (g[i][j] == 'H') valid = false;
                if (i < j && g[0][i] == 'H') valid = false;
                if (i > j && g[n - 1][i] == 'H') valid = false;
            }
            ret += valid;
        }
        // use row i
        for (int i = 1; i < n - 1; i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'H') valid = false;
                if (j < i && g[j][0] == 'H') valid = false;
                if (j > i && g[j][n - 1] == 'H') valid = false;
            }
            ret += valid;
        }
    }
    if (k >= 3) {
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                // RDRD
                bool valid = g[i][j] == '.';
                for (int a = 0; a < n; a++) {
                    if (a <= i && g[a][j] == 'H') valid = false;
                    if (a >= i && g[a][n - 1] == 'H') valid = false;
                    if (a <= j && g[0][a] == 'H') valid = false;
                    if (a >= j && g[i][a] == 'H') valid = false;
                }
                ret += valid;
                valid = g[i][j] == '.';
                // DRDR
                for (int a = 0; a < n; a++) {
                    if (a <= i && g[a][0] == 'H') valid = false;
                    if (a >= i && g[a][j] == 'H') valid = false;
                    if (a <= j && g[i][a] == 'H') valid = false;
                    if (a >= j && g[n - 1][a] == 'H') valid = false;
                }
                ret += valid;
            }
        }
    }
    cout << ret << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}