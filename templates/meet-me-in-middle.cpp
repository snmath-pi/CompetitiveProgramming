class Solution {
public:
    vector<int> generate(vector<int> &given) {
        vector<int> sums;
        sums.push_back(0);
        for(auto &x: given) {
            int n = sums.size();
            for(int i=0; i<n; i++) {
                sums.push_back(x+sums[i]);
            }
        }
        return sums;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> first(nums.begin(), nums.begin()+nums.size()/2);
        vector<int> second(nums.begin()+nums.size()/2, nums.end());
        vector<int> a = generate(first);
        vector<int> b = generate(second);

        sort(b.begin(), b.end());
        int ans=  INT_MAX;
        for(auto &x: a) {
            auto it = lower_bound(b.begin(), b.end(), goal -x);
            if(it!=b.end()) {
                ans = min(ans, abs(goal - (*(it) + x)));
            }
            if(it!=b.begin()) {
                ans = min(ans, abs(goal - (*(--it)+x)));
            }
        }
        return ans;
    }
};
