#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ll = long long;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> orderd_ms;

class Solution {
public:
    int  reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        orderd_ms os;
        for (int i = 0; i < n; i++) {
            ans += os.size() - os.order_of_key(nums[i] * 2ll + 1);
            os.insert(nums[i]);
        }
        return ans;
 
    }
};

// Using Semgent tree

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ll = long long;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> orderd_ms;
class info{
public:
    int pref , suff , sum ,ans , mx;
    void set(int val){
        pref = suff = ans = max(val , 0);
        sum = val;
        mx = val;

    }

};
class Segment_Tree
{
private:
    vector<info>tree;
    vector<int>arr;
    int sz;
public:
    Segment_Tree(int n , vector<int>a){
        sz = n;
        arr =vector<int>(n,0);
        tree = vector<info>(4*n + 1,{0,0,0,0 ,INT_MIN});
        arr = a;

    }

    info operation(info l , info r){
        info new_val ;
        new_val.set(0);
        new_val.sum = l.sum + r.sum ;
        new_val.suff = max(r.suff, l.suff + r.sum) ;
        new_val.pref = max(l.pref , l.sum + r.pref) ;
        new_val.ans =  max({l.ans,r.ans, r.pref + l.suff}) ;
        new_val.mx = max( l.mx , r.mx);

        return new_val ;
    }
    int rangeQuery(int low , int high , int qLow , int qHigh ,int pos){
        //Total overlap
        if(qLow <=low &&qHigh >=high){
            return  tree[pos].sum;
        }
        // no overlap
        if(qLow >high ||qHigh <low){
            return 0;
        }
        int mid =(low + high) / 2;
        int left = rangeQuery(low , mid ,qLow , qHigh , pos*2+1);
        int right = rangeQuery(mid+1 ,high , qLow ,qHigh ,pos*2+2);
        return left + right;
    }
    void updateValue(int low , int high , int index , int value ,int pos)
    {
        // not include in the range
        if(index <low || index >high)return;
        if(low ==high){
            tree[pos].set(tree[pos].sum + value);
            arr[low]  = value;
            return;
        }
        int mid =(low + high) / 2;
        if(index <=mid)
            updateValue(low , mid ,index,value, pos*2+1);
        else
            updateValue(mid+1 ,high , index,value ,pos*2+2);

        tree[pos] = operation(tree[2*pos+1 ] ,tree[2 * pos +2]);
    }
   
 
};
class Solution {
public:
    int  reversePairs(vector<int>& nums) {
    set<long long > uniq(nums.begin() , nums.end());
   
        int cnt = 0;
        map<int,int>pos;
        for(auto u :uniq){
            pos[u] = cnt++;
        }
        Segment_Tree seg(cnt ,{});
       int ans = 0 ;
        for(int i = 0 ; i <nums.size() ; i++){
            long long value = nums[i] * 2LL + 1LL;
            auto idx = uniq.lower_bound(value);
            if(idx !=uniq.end()){
                int st = pos[*idx] , en =  cnt - 1;
                ans += seg.rangeQuery(0 , en , st, en , 0);
            }  
            seg.updateValue(0 , cnt-1 , pos[nums[i]] , 1 , 0);
        }
        return ans;
 
    }
};
