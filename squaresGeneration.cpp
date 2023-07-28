#include <bits/stdc++.h>
using namespace std;

// There is a two-dimensional plane. For integers r and c between 1 and 9, there is a pawn at the coordinates (r,c)
// if the c-th character of Sr is #, and nothing if the c-th character of Sr is .

// Find the number of squares in this plane with pawns placed at all four vertices.

int main()
{
    vector<string> s(9);
    for (auto &v : s)
        cin >> v;
    auto valid = [&](int x, int y)
    {
        return clamp(x, 0, 8) == x and clamp(y, 0, 8) == y and s[x][y] == '#';
    };
    set<set<pair<int, int>>> st;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int dx = -8; dx < 9; dx++)
            {
                for (int dy = -8; dy < 9; dy++)
                {
                    if (!dx and !dy)
                        continue;
                    int i2 = i + dx, j2 = j + dy;
                    int i3 = i2 - dy, j3 = j2 + dx;
                    int i4 = i3 - dx, j4 = j3 - dy;
                    if (valid(i, j) and valid(i2, j2) and valid(i3, j3) and valid(i4, j4))
                    {
                        set<pair<int, int>> sq;
                        sq.insert({i, j});
                        sq.insert({i2, j2});
                        sq.insert({i3, j3});
                        sq.insert({i4, j4});
                        st.insert(sq);
                    }
                }
            }
        }
    }
    cout << st.size() << endl;
}
