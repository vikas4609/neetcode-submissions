class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype([](const vector<int>& a, const vector<int>& b){
            return sqrt(a[1]*a[1] + a[0]*a[0]) < sqrt(b[1]*b[1] + b[0]*b[0]);
        })> pq;
        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            pq.pop();
        }
        return vec;
    }
};
