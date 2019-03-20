/*
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 *
*/





#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int dp[1000][1000] = {0};
        int left = 0, right = 0, length = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = 0; j < i; j++){
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]));
                if (dp[j][i] && length < i - j + 1){
                    length = i - j +1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left,right - left +1);
    }
};


int main(){
	Solution M;
	string s = "caba";
	string n = M.longestPalindrome(s);
	cout << n << endl;

	return 0;
}
