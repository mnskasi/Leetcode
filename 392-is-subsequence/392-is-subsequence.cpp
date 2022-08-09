class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t) {
            return true;
        }
        if (s.size() > t.size()) {
            return false;
        }
        int sind = 0;
        for (int i =0;i< t.size();i++) {
            if (t[i] == s[sind]) {
                sind++;
            }
            if (sind == s.size()) {
                return true;
            }
        }
        return false;
    }
};