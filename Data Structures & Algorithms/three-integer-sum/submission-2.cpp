class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = nums[i]*(-1);
            int x = i+1;
            int y = nums.size()-1;
            while(x<y){
                if(nums[x]+nums[y] == target){
                    if(y!=nums.size()-1 && nums[x] == nums[x-1] && nums[y] == nums[y+1]){
                        x++;
                        y--;
                        continue;
                    }
                    ans.push_back({nums[i], nums[x], nums[y]});
                    x++;
                    y--;
                }else if(nums[x]+nums[y] > target){
                    y--;
                }else{
                    x++;
                }
            }
        }
        return ans;
    }
};
