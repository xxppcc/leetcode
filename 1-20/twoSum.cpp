class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
