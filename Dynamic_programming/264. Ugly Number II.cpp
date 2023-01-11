class Solution {
public:
    long long nthUglyNumber(int n) {
     vector<long long >vals(n+1 , -1);
     vals[1] = 1;
     int idx2 ,idx3 , idx5;
     idx2 = idx3 = idx5 = 2 ;
     for(int i = 2 ; i<=n;i++){
       long long f = vals[idx2-1] * 2;
       long long s = vals[idx3-1] * 3;
       long long  t =vals[idx5-1] * 5;
       long long minVal = min({f,s,t});
       idx2 = (f==minVal ?idx2+1:idx2);
       idx3 = (s==minVal ?idx3+1:idx3);
       idx5 = (t==minVal ?idx5+1:idx5);
       vals[i] = minVal;

     }
     return vals[n];
    }
};
