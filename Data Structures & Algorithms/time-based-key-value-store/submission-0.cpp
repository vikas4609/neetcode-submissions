class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> p1 = {timestamp, value};
        mp[key].push_back(p1);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> vec = mp[key];
        if(vec.size()==0){
            return "";
        }
        if(vec[0].first > timestamp){
            return "";
        }
        int i=0;
        int j=vec.size()-1;
        string val;
        while(i<=j){
            int mid = (i+j)/2;
            if(timestamp == vec[mid].first){
                return vec[mid].second;
            }else if(timestamp > vec[mid].first){
                i = mid+1;
                val = vec[mid].second;
            }else {
                j = mid-1;
            }
        }
        return val;
    }
};
