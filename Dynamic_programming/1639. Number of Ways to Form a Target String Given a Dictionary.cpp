class Solution {
public:
  int dp[1001][1001];
  const int Mod = 1e9 + 7;
int solve(vector<vector<int>> &cnt, string &t, int i, int j) {
    if (j >= t.size())
        return 1;
    int &ans = dp[i][j];
    if(ans !=0)return ans;
    ans = 0;
    if (dp[i][j] == 0) {
       
        for (int k = i; k + (t.size() - j) <= cnt.size(); ++k)
            if (cnt[k][t[j] - 'a'])
                ans  = ((long)cnt[k][t[j] - 'a'] * solve(cnt, t, k + 1, j + 1) + ans) % Mod;
    }
    return ans;
}
    int numWays(vector<string>& words, string target) {
      vector<vector<int>> cnt(words[0].size(), vector<int>(26));
    for (auto &w : words)
        for (auto i = 0; i < w.size(); ++i)
            ++cnt[i][w[i] - 'a'];
    return solve(cnt, target, 0, 0);
    }
};
