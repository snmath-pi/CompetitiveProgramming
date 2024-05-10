class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0.0, r = 1.0;
        for(int iter = 100; iter; iter--) {
            double m = l + (r-l)/2.0;

            double res = 0.0;
            int tot = 0, nu = 0, de = 0;
            for(int j = 1, i = 0; i < n - 1; i++) {
                while(j < n && arr[i] >= m * arr[j]) j++;
                tot += n - j;
                if(j == n)break;

                double cur = arr[i] / (double) arr[j];
                if(cur > res) {
                    res = cur;
                    nu = i, de = j;
                }
            }
            if(tot == k) {
                return {arr[nu], arr[de]};
            } else if(tot < k) l = m;
            else r = m;
        }
        return {};
    }
};
