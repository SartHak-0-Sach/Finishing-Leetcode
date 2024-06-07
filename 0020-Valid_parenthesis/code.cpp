#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char arr[100001];
        int top=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                arr[++top]=s[i];
            }else{
                if(top==-1) return false;
                if((s[i]==')' && arr[top]=='(') || (s[i]=='}' && arr[top]=='{') || (s[i]==']' && arr[top]=='['))    top--;
                else    return false;
            }
        }
        return top==-1;
    }
};