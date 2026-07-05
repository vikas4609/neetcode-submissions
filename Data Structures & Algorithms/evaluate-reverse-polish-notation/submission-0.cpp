class Solution {
public:
    int convert(string s){
        int multi = 1;
        int answer = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '-'){
                return answer*(-1);
            }else{
                answer = answer + (s[i] - '0')*multi;
                multi = multi*10;
            }
        }
        return answer;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                string sec = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                st.push(to_string(convert(first) + convert(sec)));
            }else if(tokens[i] == "-"){
                string sec = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                st.push(to_string(convert(first) - convert(sec)));
            }else if(tokens[i] == "*"){
                string sec = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                st.push(to_string(convert(first) * convert(sec)));
            }else if(tokens[i] == "/"){
                string sec = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                st.push(to_string(convert(first)/convert(sec)));
            }else{
                st.push(tokens[i]);
            }
        }
        return convert(st.top());
    }
};
