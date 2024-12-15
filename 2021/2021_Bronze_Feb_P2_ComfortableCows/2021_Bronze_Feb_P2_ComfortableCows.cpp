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

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0,0, -1, 1 };
bool area[1001][1001];
int good = 0;

bool ReadInFile(const string& sFile, vector<pair<int, int>>& grid, int& n)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }


    in >> n;

    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        in >> temp1 >> temp2;

        grid.push_back(std::make_pair(temp1, temp2));
    }

    return true;
}

bool valid_pos(const int x, const int y, const int n)
{
    return x >= 0 && x <= n && y >= 0 && y <= n;
}

bool comfy(const int x, const int y, const int n)
{
    if (area[x][y] == 0)
    {
        return 0;
    }

    int neighbors = 0;
    for (int d = 0; d < 4; d++)
    {
        if (valid_pos(x,y, n))
        {
            if (area[x][y])
            {
                neighbors++;
            }
        }
    }

    return neighbors == 3;
}


void Print(const vector<pair<int, int>> grid)
{
    cout << grid.size() << endl;

    for (int i = 0; i < grid.size(); i++)
    {
        cout << grid[i].first << " " << grid[i].second << endl;
    }

}

bool ReadInCout(vector<pair<int, int>>& grid)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        grid.push_back(std::make_pair(temp1, temp2));
    }

    return true;
}

int main()
{
    int n =0;
    vector<pair<int, int>> grid;

    bool bOk = ReadInFile("../prob2_bronze_feb21/1.in", grid, n);
    //ReadInCout(grid);
    //Print(grid);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int d = 0; d < 4; d++)
        {
            int x = grid[i].first + dx[d];
            int y = grid[i].second + dy[d];

            if (valid_pos(x,y,n))
            {
                good -= comfy(x,y,n );
            }
        }
        area[grid[i].first][grid[i].second] = 1;

        for (int d = 0; d < 4; d++)
        {
            int x = grid[i].first + dx[d];
            int y = grid[i].second + dy[d];
            if (valid_pos(x, y, n))
            {
                good += comfy(x, y,n );
            }

        }

        good += comfy(grid[i].first, grid[i].second,n);
        ans.push_back(good);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
}