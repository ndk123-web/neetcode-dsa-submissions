class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for (int& num : nums)
            pq.push(num);

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }      

        reverse(res.begin(), res.end());
        return res;
    }
};