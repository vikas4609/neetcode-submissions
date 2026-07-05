class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1.size() + nums2.size();
        int i1=0;int i2=0;
        vector<int> vec;
        while(i1<nums1.size() || i2<nums2.size()){
            if(i1 == nums1.size()){
                while(i2<nums2.size()){
                    vec.push_back(nums2[i2]);
                    i2++;
                }
            }
            if(i2 == nums2.size()){
                while(i1<nums1.size()){
                    vec.push_back(nums1[i1]);
                    i1++;
                }
            }
            if(i1<nums1.size() && i2<nums2.size()){
                while(i1<nums1.size() && i2<nums2.size() && nums1[i1]<=nums2[i2]){
                    vec.push_back(nums1[i1]);
                    i1++;
                }
                while(i1<nums1.size() && i2<nums2.size() && nums2[i2]<=nums1[i1]){
                    vec.push_back(nums2[i2]);
                    i2++;
                }
            }
        }

        return t%2==0 ? (double(vec[t/2])+double(vec[(t/2)-1]))/2 : vec[t/2];
    }
};
