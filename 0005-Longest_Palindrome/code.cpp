#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int resstart=0, reslen=1;
        if(s.size()==1)return s;
        int start=0;
        for(int i=0;i<s.size();i++){
            start=i;
            while(i+1<s.size()&& s[i]==s[i+1])
                i++;
            int end=i+1;
            start--;
            while(start>=0 && end<s.size() && s[start]==s[end]){
                start--;
                end++;
            }
            start++;
            end--;
            if(reslen<end-start+1){
                reslen=end-start+1;
                resstart=start;
            }
        }
        return s.substr(resstart, reslen);
    }
};