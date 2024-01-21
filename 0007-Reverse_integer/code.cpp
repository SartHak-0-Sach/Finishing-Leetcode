#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool negativeNum = false;
        if (x < 0) {
            negativeNum = true;
            x = std::abs(x);
        }
        while (x > 0) {
            int lastDigit = x % 10;
            ans *= 10;
            ans += lastDigit;
            x /= 10;
            if (ans > (INT_MAX - lastDigit) / 10 && x > 0)
                return 0;
        }
        if (negativeNum)
            return -1 * ans;

        else
            return ans;
    }
};