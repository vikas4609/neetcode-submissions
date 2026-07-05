class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size()-1;
        if(nums[i] < nums[j]){
            return nums[i];
        }
        while(i<j){
            int mid = (i+j)/2;
            if(mid == 0){
                return nums[mid]<nums[mid+1] ? nums[mid] : nums[mid+1];
            }else if(mid == nums.size()-1){
                return nums[mid]<nums[mid-1] ? nums[mid] : nums[mid-1];
            }
            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                if(nums[mid] > nums[0]){
                    i = mid;
                }else{
                    j = mid-1;
                }
            }else if(nums[mid-1] > nums[mid] && nums[mid]<nums[mid+1]){
                return nums[mid];
            }else if(nums[mid-1] < nums[mid] && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
        }
        return nums[i];
    }
};
