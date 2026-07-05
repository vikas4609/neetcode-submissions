class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> answer(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && st.top().first<temperatures[i]){
                pair<int, int> temp = st.top();
                answer[temp.second] = i-temp.second;
                st.pop();
            }
            pair<int, int> p1{temperatures[i],i};
            st.push(p1);
        }
        return answer;
    }
};
