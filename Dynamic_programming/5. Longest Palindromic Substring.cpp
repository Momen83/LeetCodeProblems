class Solution {
public:
    int mem[1001][1001];
    string str1;
    string ans="";
    int val;
    deque<char>before,after;
    void init()
{
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            mem[i][j]=-1;
        }
    }
}
   int editDistance(int i, int j)
{
    if(i>j)
        return 0;
   if(i==j)
       return 1;
    int &ret = mem[i][j];

    if(ret != -1)
        return ret;

    if(str1[i] == str1[j])
    {
        int rem=j-i-1;
        if(rem== editDistance(i+1,j-1))
            return 2+rem;
    }

    int choice1 =  editDistance(i, j-1);
    int choice2 = editDistance(i+1, j);

    return ret = max(choice1,(choice2));
    /*
     * abdba
     */
}
    void print2(int i, int j)
{
    if(i>j)
        return;
    if(i==j)
    {
        if(val&1)before.push_back(str1[i]);
        return;
    }
    if(str1[i] == str1[j])
    {
        int rem=j-i-1;
        if(rem== editDistance(i+1,j-1) )
        {
            before.push_back(str1[i]);
            after.push_front(str1[j]);
            print2(i+1,j-1);
        }
        else
        {
            int choice1 =  editDistance(i, j-1);
            int choice2 = editDistance(i+1, j);
            int op= editDistance(i,j);
            if(op==choice1)print2(i,j-1);
            else print2(i+1,j);
        }

    }
       else
    {
        int choice1 =  editDistance(i, j-1);
        int choice2 = editDistance(i+1, j);
        int op= editDistance(i,j);
        if(op==choice1)print2(i,j-1);
        else print2(i+1,j);
    }
       
}

    string longestPalindrome(string s) {
        str1=s;
        init();
           val=editDistance(0,str1.size()-1);
           print2(0,str1.size()-1);
         for (int i = 0; i < before.size(); ++i) {
       ans+=before[i];
    }
    for (int i = 0; i < after.size(); ++i) {
        ans+=after[i];
    }
        return ans;
    }
};
