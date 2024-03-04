#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> visited(26,0);
//         int max_length;
//         int count = 0;
//         for(int i = 0; i<s.length(); i++)
//         {
//             visited[s[i]-96] += 1;
//             count++;
//             if(visited[s[i]-96] > 1)
//             {
//                 for(int j = 0; j<=i; j++)
//                 {
//                     visited[s[j]-96] = 0;
//                 }
//                 if(count-1>max_length)
//                 {
//                     max_length = count-1;
//                 }
//                 count = 0;
//             }
//         }
//         return max_length;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // Initialize an array to store the last index of each character's occurrence
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};

// unoptimised alternate approaches
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int maxLength = 0;
//         unordered_map<char, int> charMap;
//         int left = 0;
        
//         for (int right = 0; right < n; right++) {
//             if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
//                 charMap[s[right]] = right;
//                 maxLength = max(maxLength, right - left + 1);
//             } else {
//                 left = charMap[s[right]] + 1;
//                 charMap[s[right]] = right;
//             }
//         }
        
//         return maxLength;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         map<char,int> mp;
//         queue<char> q;
//         int maxLen = INT_MIN;
//         for(int i=0;i<s.size();i++)
//         {
//             if(q.empty())
//             {
//                 q.push(s[i]);
//                 mp[s[i]]++;
//             }
//             else if(mp[s[i]]){
//                 while(!q.empty() && mp[s[i]] > 0)
//                 {
//                     int qs = q.size();
//                     maxLen = max(maxLen,qs);
//                     if(mp[q.front()] > 0)
//                         mp[q.front()]--;
//                     q.pop();
//                 }
//                 q.push(s[i]);
//                 mp[s[i]]++;
//             }
//             else{
//                 q.push(s[i]);
//                 mp[s[i]]++;
//             }
//         }
//         int qs = q.size();
//         maxLen = max(maxLen,qs);
//         return maxLen;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.size()==0)
//         return 0;
//         int start = 0, end = 0;
//         int ans = 0;
       
//         int len =INT_MIN;
//         unordered_map<char,int> m;
//         while(end<s.size())
//         {
//             string k="hello";
//                 while(end<s.size() && m[s[end]]<=0)
//                 {
//                      m[s[end]] =1;
//                     k+=s[end];
//                     end++;
//                     ans++;
                   
//                 }
//                 cout<<k<<endl;
//                 len = max(len,ans);
//                 while(start <= end && m[s[end]]==1)
//                 {cout<<"Endyer"<<endl;
//                      m[s[start]]--;
//                     start++;
//                     ans--;
                   
//                 }
               
//         }
//         return len;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         std::list<char> substringList;
//         int longestStringLength = 0;
//         int leftPointer = 0;
//         int rightPointer = 0;

//         for(int i = 0; i < s.size(); i++)
//         {
            
//             while(std::find(substringList.begin(), substringList.end(), s[rightPointer]) != substringList.end())
//             {
//                 substringList.remove(s[leftPointer]);
//                 leftPointer++;
//             }
//             substringList.push_back(s[rightPointer]);
//             rightPointer++;
//             int substringLength = rightPointer - leftPointer;
//             if(longestStringLength < substringLength)
//             {
//                 longestStringLength = substringLength;
//             }
//         }

//         return longestStringLength;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         string substring;
//         int longest_substring = 0;
        
//         for (int i = 0; i < s.size(); i++) {
//             int j = i;
//             int substring_length = 0;
//             substring = "";
            
//             while (j < s.size()) {
//                 if (substring.find_first_of(s[j], 0) != -1) {
//                     break;
//                 }
//                 substring += s[j];
//                 substring_length += 1;
//                 j += 1;
//             }
//             if (substring_length > longest_substring) {
//                 longest_substring = substring_length;
//             }
//         }
//         return longest_substring;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int lMax = 0;
//         int l, r;
//         for (l = 0, r = 0; r < s.size(); r++){
//             string substring = s.substr(l, r - l + 1);
//             sort(substring.begin(), substring.end());
//             if (unique(substring.begin(), substring.end()) != substring.end()){
//                 lMax = max(lMax, r - l);
//                 l++;
//             }   
//         }
//         lMax = max(lMax, r - l);
//         return lMax;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
       
//         int maxLen = 0;
//         for(int i =0;i<n;i++){
//             unordered_set<char> set;

//             int j =0;
//             for( j =i;j<n;j++){
//                 if(set.find(s[j])!=set.end()){
//                     maxLen =max(maxLen,j-i);
//                     break;
//                 }
//                 set.insert(s[j]);
//             }
//             if(j==n){
//                maxLen =max(maxLen,j-i); 
//             }
            
//         }

//         return maxLen;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int ans = 0;
//         int i=0;
//         while(i<n)
//         {
//             vector<int> chars;
//             chars.push_back(s[i]);
//             int j=i+1;
//             while(j<n)
//             {
//                 vector<int>::iterator it = find(chars.begin(),chars.end(),s[j]);
//                 if(it==chars.end())
//                 {
//                     chars.push_back(s[j]);
//                     j++;
//                 }
//                 else break;
//             }
//             if(ans<chars.size())ans=chars.size();
//             i++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         string subs="";
//         int max=0;
//         for(int i=0;i<s.size();i++){
//             subs=s[i];
//             int j=i+1;
//            while(!count(subs.begin(),subs.end(),s[j]) && j<s.size()){
//                subs+=s[j];
//                j++;
//            }
//            if(subs.size()>max){
//              max = subs.size();
//            }
//            if(j==s.size()-1){
//                break;
//            }
//         }
//     return max;
//     }
// };