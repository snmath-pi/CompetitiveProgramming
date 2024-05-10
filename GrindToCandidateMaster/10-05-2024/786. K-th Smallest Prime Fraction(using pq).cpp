class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        
        int n = arr.size();
        for(int i=0; i<n; i++) {
            pq.push({-arr[i] / (double) arr[n-1], {i, n-1}});
        }
        
        while(--k > 0) {
            auto [u, v] = pq.top();
            pq.pop();
            v.second--;
            pq.push({-arr[v.first] / (double) arr[v.second], {v.first, v.second}});
        }
        auto [v, u] = pq.top();
        return {arr[u.first], arr[u.second]};
    }
};
