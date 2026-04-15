/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
    
        // nlogn
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // now just need to check wrt to start of current and end of next 
        // if e < ns then its left one 
        for (int i = 0; i < n - 1; i++) {
            
            Interval& first = intervals[i];
            Interval& second = intervals[i + 1];

            // overlap exist 
            if (first.end > second.start) {
                return false;
            }
        }

        return true;
    }
};
