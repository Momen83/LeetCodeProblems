class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m =word2.size();
        if(n!=m){
            return false;
        }
        vector<int>freq(26,0);
        vector<int>freq2(26,0);
        for(int i =0 ;i<n;i++){
            freq[word1[i]-'a']++;
            freq2[word2[i] -'a']++;
        }
        vector<int>values1,values2;
        for(int i =0 ; i<26;i++){
            if(freq[i]== 0 &&freq2[i] ||(freq2[i]== 0 &&freq[i] )){
                return false;
            }
            values1.push_back(freq[i]);
            values2.push_back(freq2[i]);
        }
        sort(values1.begin(),values1.end());
        sort(values2.begin(),values2.end());
        if(values1!=values2){
            return false;
        }
        return true;
    }
};
