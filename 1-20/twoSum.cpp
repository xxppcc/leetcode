/* 
* 给定一个整数数组 nums 和一个目标值 target，
* 请你在该数组中找出和为目标值的那 两个 整数，
* 并返回他们的数组下标。

* 你可以假设每种输入只会对应一个答案。
* 但是，你不能重复利用这个数组中同样的元素。
示例:
	给定 nums = [2, 7, 11, 15], target = 9
	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// unordered_map(哈希表)
        map<int, int> hash;
        vector<int> index(2,0);
        for (int i=0; i < nums.size(); i++){
            if (hash.find(target - nums[i]) != hash.end()){
										index[0] = hash[target - nums[i]];
										index[1] = i;
                break;
            }
            hash.insert(pair<int,int>(nums[i],i));
        }
        return index;
        
    }
};

int main(){
	int arr[4] = {2,7,11,15};
	vector<int> nums(arr,arr+4);
	int target = 26;
	Solution M ;
	vector<int> index = M.twoSum(nums,target);
	cout << "index1 = " << index[0] << endl;
	cout << "index2 =  "<< index[1] << endl;
	return 0 ;
}
