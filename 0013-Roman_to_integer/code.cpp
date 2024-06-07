#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int getVal(char symbol){
        switch(symbol){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(i + 1 < s.size() && getVal(s[i]) < getVal(s[i+1])){
                res -= getVal(s[i]);
            }
            else{
            res += getVal(s[i]);
            }
        }
        return res;
    }
};