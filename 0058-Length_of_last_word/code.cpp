#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = s.length()-1;
        while(s[k]==' ')
        k--;

        int count = 0;
        for(int i = k; s[i]!=' '; i--)
        {
            count++;
            if(i==0)
            break;
        }

        return count;
    }
};