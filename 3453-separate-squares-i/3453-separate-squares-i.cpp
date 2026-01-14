class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double ymx=0,ta=0;
        for(auto& sq:squares){
            int y=sq[1],l=sq[2];
            ta+=(double)l*l;
            ymx=max(ymx,double(y+l));
        }
        auto chk=[&](double y)->bool{
            double ar=0;
            for(auto& sq:squares){
                int y1=sq[1],l1=sq[2];
                if(y1<y)
                 ar+=l1*min(y-y1,(double)l1);
            }
            return ar>=ta/2;
        };
        double lo=0,hi=ymx;
        double eps=1e-5;
        while(abs(hi-lo)>=eps){
            double md=(hi+lo)/2;
            if(chk(md)){
                hi=md;
            }
            else lo=md;
        }
        return hi;
    }
};