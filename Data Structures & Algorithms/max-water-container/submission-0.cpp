class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size()-1;
        int answer=0;
        while(start<end){
            int temp;
            if(heights[start] < heights[end]){
                temp = heights[start]*(end-start);
                if(temp>answer){
                    answer = temp;
                }
                start++;
            }else if(heights[start] > heights[end]){
                temp = heights[end]*(end-start);
                if(temp>answer){
                    answer = temp;
                }
                end--;
            }else{
                temp = heights[end]*(end-start);
                if(temp>answer){
                    answer = temp;
                }
                start++;
                end--;
            }
        }
        return answer;
    }
};
