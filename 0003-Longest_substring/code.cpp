#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    vector<int> visited(256, -1);
    int start = -1;
    int maxLen = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (visited[str[i]] > start)
        {
            start = visited[str[i]];
        }
        visited[str[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    cout << maxLen << endl;
    return 0;
}