class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";

        path += '/';

        for (char ch : path) {
            if (ch == '/') {

                if (temp == "" || temp == ".") {
        
                }
                else if (temp == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else {
                    st.push(temp);
                }

                temp.clear();
            }
            else {
                temp += ch;
            }
        }
        vector<string> dirs;

        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans = "";

        for (string &dir : dirs) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};