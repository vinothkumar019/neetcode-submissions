class Solution {
public:
    string decodeString(string s) {

        stack<int> countSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }
            else if (ch == ']') {
                int k = countSt.top();
                countSt.pop();

                string temp = strSt.top();
                strSt.pop();

                while (k--) {
                    temp += curr;
                }

                curr = temp;
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};