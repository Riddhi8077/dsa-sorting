class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st; 
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            else {
                st.push_back(token);
            }
        }

        string canonicalPath = "";
        for (const string& dir : st) {
            canonicalPath += "/" + dir;
        }

        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};
