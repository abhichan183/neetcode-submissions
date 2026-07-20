class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int start, string &s) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int end = start; end < s.size(); end++) {

            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(end + 1, s);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};