class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int end = 0;
        int answer=0;
        while(end<prices.size()){
            if((prices[end]-prices[start])>answer){
                answer = prices[end]-prices[start];
            }
            if(end<(prices.size()-1) && prices[end+1]<=prices[start]){
                end++;
                start = end;
            }else{
                end++;
            }
        }
        return answer;
    }
};
