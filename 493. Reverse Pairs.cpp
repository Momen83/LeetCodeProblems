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
