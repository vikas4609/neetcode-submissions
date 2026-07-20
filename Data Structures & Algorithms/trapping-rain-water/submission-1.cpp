class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int answer = 0;
        int maxin = 0;
        while(i<height.size()){
            int j = i+1;
            int temp = 0;
            while(j<height.size() && height[j]<height[i]){
                temp = temp + (height[i]-height[j]);
                j++;
            }
            if(j != height.size()){
                answer = answer + temp;
            }else {
                maxin = i;
            }
            i = j;
        }
        i=height.size()-1;
        while(i>=maxin){
            int j = i-1;
            int temp = 0;
            while(j>=maxin && height[j]<height[i]){
                temp = temp + (height[i]-height[j]);
                j--;
            }
            if(j != -1){
                answer = answer + temp;
            }
            i = j;
        }
        return answer;
    }
};
