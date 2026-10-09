#define acc accumulate
class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        if(acc(g.begin(),g.end(),0)<acc(c.begin(),c.end(),0)){
            return -1;
        }
        int t=0;
        int r =0;

        for(int i=0; i<g.size(); i++){
            t+=(g[i]-c[i]);

            if(t<0){
                t=0;
                r =i+1;
            }
        }
        return r;
    }
};
