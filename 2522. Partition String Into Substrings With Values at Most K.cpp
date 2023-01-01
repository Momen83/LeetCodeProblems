class Solution {
public:
    int minimumPartition(string s, int k) {
        int cnt = 0;
        long long  val = 0;
        for(int j = 0 ;j<s.size();j++){
            if(val ==0){
                if(val + (s[j]-'0') >k){
                    cnt = -1;
                    break;
                }
                else{
                    val  = val*10 + (s[j]-'0');
                }
            }
            else if(val*10 +(s[j]-'0') >k ){
                val = 0;
                j--;
                cnt++;
            }
            else{
                val  = val*10 + (s[j]-'0');
            }
        }
        return cnt +=(val>0);
    }
};
