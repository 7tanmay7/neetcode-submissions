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
    bool canAttendMeetings(vector<Interval>& a) {
        sort(a.begin(),a.end(),
                [](Interval& x, Interval& y){
             return x.start < y.start; });
        for(int i=1; i<a.size(); i++){
            if(a[i].start<a[i-1].end){
                return false;
                
            }
        }
        return true;
    }
};
