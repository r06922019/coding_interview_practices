class Solution {
public:
    string decodeString(string s) {
        vector<string> str_st;
        stack<int> int_st;
        int cur_num = 0;
        for(auto &c : s) {
            if(c == ']') {
                string tmp = "", tmp_ans = "";

                // pop until "["
                int index = str_st.size()-1;
                while(str_st[index] != "[") --index;
                for(int i = index+1; i < str_st.size(); ++i)
                    tmp += str_st[i];
                while(str_st.size() > index) str_st.pop_back();

                int num = int_st.top();
                int_st.pop();
                while(num--)
                    tmp_ans += tmp;
                str_st.push_back(tmp_ans);
            }
            else if(c == '[') {
                str_st.push_back("[");
                int_st.push(cur_num);
                cur_num = 0;
            }
            else if(isdigit(c)) {
                cur_num = cur_num * 10 + (c - '0');
            }
            else {
                str_st.push_back(string(1, c));
            }
        }

        string ans = "";
        for(auto &s : str_st) ans += s;
        return ans;
    }
};