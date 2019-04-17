#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1) return s;
		
		vector<string> curRows(min(numRows,int(s.size())));
		int row = 0;
		bool goingDown = false;

		for (char c : s){
			curRows[row] += c;
			if (row == 0 || row == numRows - 1) goingDown = !goingDown;
			row += goingDown ? 1 : -1;
		}

		string ret ;
		for (string s : curRows) ret += s;
		
		return ret; 
    }
};

int main(){
	Solution M;
	string s = "PAYPALISHIRING";
	int n = 3;
	cout << "out:" << M.convert(s,n) << endl;

	return 0;


}
