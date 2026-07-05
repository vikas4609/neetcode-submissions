class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m] == target){
                return m;
            }
            if(nums[m]>nums[r]){
                if(target>nums[m] || target<=nums[r]){
                    l = m+1;
                }else if(target<nums[m]){
                    r = m;
                }
            }else{
                if(target<nums[m] || target>nums[r]){
                    r = m;
                }else if(target > nums[m]){
                    l = m+1;
                }
            }
        }
        if(nums[l] == target){
            return l;
        }
        return -1;
    }
};
