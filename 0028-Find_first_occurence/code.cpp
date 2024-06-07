#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size()) return -1;

        int index = 0;
        bool match = false;

        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            index = 0;
            match = false;
            for (int j = i; j < i + needle.size(); j++)
            {
                if (haystack[j] != needle[index])
                {
                    match = true;
                    break;
                }
                index++;
            }
            if (match)
                continue;
            return i;
        }
        return -1;
    }
};