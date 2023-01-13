class Solution {
public:
 bool matching(string s1 , string s2){
       int cnt = 0 ;
       for(int i = 0 ;i<s1.size();i++){
           cnt+=(s1[i] !=s2[i]);
       }
       return  cnt ==1;
   }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          queue<pair<string,int>>q;
        unordered_map<string,bool>vis;
        int ans = 0;
        q.push({beginWord,1});
        for(int i = 0 ;i<wordList.size() ; i++){
            vis[wordList[i]] = true;
        }
        vis[beginWord] = true;
         while(!q.empty()){
            string word = q.front().first;
             int level = q.front().second;
             q.pop();
             if(word == endWord )return level;
              for(int i = 0 ;i<word.size();i++){
                   char value  = word[i];
                   for(char v = 'a' ;v<='z';v++){
                        word[i] = v;
                         if(vis.find(word) !=vis.end()){
                        q.push({word,level+1});
                        vis.erase(word);
                     }
                   }
                   word[i] = value;
                   
                }
            }
            return 0;
        }
       
    
};
