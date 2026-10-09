
class Solution {
public:
    static bool cmp(Interval& x, Interval& y){
        return x.start < y.start;
    }
    int minMeetingRooms(vector<Interval>& a){ if(a.empty())
    return 0;

    sort(a.begin(),a.end(), cmp);

    priority_queue<int, vector<int>, greater<int>>pq;

    pq.push(a[0].end);

    for(int i =1; i<a.size(); i++){

        if(a[i].start >= pq.top()){
            pq.pop();
        }
        pq.push(a[i].end);
    }

    return pq.size();
      
    }
};
