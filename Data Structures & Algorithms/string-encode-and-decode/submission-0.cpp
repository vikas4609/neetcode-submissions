class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(string s : strs){
            int len = s.length();
            enc = enc + to_string(len) + "#" + s;
        }
        cout<<"encoded"<<enc<<"\n";
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> dec;
        int i=0;
        while(i<s.length()){
            int j=i;
            string str = "";
            while(s[j] != '#'){
                str = str+s[j];
                j++;
            }
            int len = stoi(str);
            string temp = s.substr(j+1, len);
            dec.push_back(temp);
            i = len+j+1;
        }
        return dec;
    }
};
