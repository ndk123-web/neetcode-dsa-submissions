class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        int n = s.size();

        // step 1
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') 
                left.push(i);
            
            else if (s[i] == '*')       
                star.push(i);
            
            else {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }

        // step 2       
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()){
                return false;
            }
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
