class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int& num : nums)
            pq.push(num);

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }      
        return res;
    }
};