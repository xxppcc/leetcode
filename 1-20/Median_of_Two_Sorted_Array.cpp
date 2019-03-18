/*
 *	给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *  请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *	你可以假设 nums1 和 nums2 不会同时为空。
 *  示例 1:
 *	nums1 = [1, 3]
 *	nums2 = [2]
 *	则中位数是 2.0
 *
 *	示例 2:
 *	nums1 = [1, 2]
 *	nums2 = [3, 4]
 *	则中位数是 (2 + 3)/2 = 2.5
 *
*/
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multimap<int, double> arr;
        int index = 1;
        int total = nums1.size() + nums2.size();
        double median = 0;
        for (auto it = nums1.begin(); it != nums1.end(); it++){
            arr.insert(make_pair(*it,*it));
        }
        for (auto it = nums2.begin(); it != nums2.end(); it++){
            arr.insert(make_pair(*it,*it));
        }
        int k = total % 2 == 0 ? total/2 : total/2 +1;
        for (auto it = arr.begin(); it != arr.end(); it++){
            if (index == k){
                median = total%2 == 0 ? (it->second+ (++it)->second)/2 : it->second;
                return median;
            }
            index++;
        }
        return median;
    }
};

int main(){
	Solution M;
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3,4};
	
	cout << M.findMedianSortedArrays(nums1,nums2) << endl;

	return 1;
}
