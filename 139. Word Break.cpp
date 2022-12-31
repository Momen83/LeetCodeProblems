class Solution {
public:
  set<string>dic;
  string word;
  int dp[301];
  int solve(int idx){
      if(idx==word.size())return 1;
        int &ret=dp[idx];
      if(ret!=-1)return ret;
      ret=0;
      for(int i=idx;i<word.size();i++){
          string temp=word.substr(idx, i-idx+1);
          if(dic.find(temp)!=dic.end() &&solve(i+1)){
             return ret=1;
          }
      }
      return ret;
  }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            dic.insert(wordDict[i]);
        }
        word=s;
        for(int i=0;i<301;i++)dp[i]=-1;
        return solve(0);
    }
};
