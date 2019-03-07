/* 
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 示例:
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
*/

#include <iostream> 
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int val = 0;
        int left = -1;
        for (int i = 0;i < s.size();i++){
            if(m.count(s[i]) && m[s[i]] > left){
                left = m[s[i]];
            }
            m[s[i]] = i;
            val = max(val,i-left);
        }
        return val;
    }  
};


int main(){
	string s1 = "abcabcbb";
	string s2 = "bbbbb";
	string s3 = "pwwkew";
	Solution M ;
	cout << "s1: "<< M.lengthOfLongestSubstring(s1) << endl;
	cout << "s2: "<< M.lengthOfLongestSubstring(s2) << endl;
	cout << "s3: "<< M.lengthOfLongestSubstring(s3) << endl;


	return 0;
}
