#define ll long long
class SegmentTree {
    private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs; //compressed x coord
    int n;

    void modify (int qleft, int qright, int qval, int left, int right, int pos){
        if(xs[right + 1]<=qleft || xs[left]>= qright) return;
        if(qleft <= xs[left] && xs[right+1]<= qright) count[pos]+=qval;
        else{
            int md=(left+right)/2;
            modify(qleft,qright,qval,left,md,pos*2+1);
            modify(qleft,qright,qval,md+1,right,pos*2+2);
        }
        if(count[pos]>0) covered[pos]=xs[right+1]-xs[left];
        else{
            if(left==right) covered[pos]=0;
            else covered[pos]=covered[pos*2+1]+covered[pos*2+2];
        }
    }

    public:
     SegmentTree (vector<int>& xs_) :xs(xs_){
        n=xs.size()-1;
        count.resize(4*n,0);
        covered.resize(4*n,0);
     }
     void update (int qleft,int qright,int qval ){
        modify(qleft,qright,qval,0,n-1,0);
     }
     int query(){
        return covered[0];

     }
};
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int,int,int,int>> events;
        set<int>xsset;
        for(auto sq:squares){
            events.push_back({sq[1],1,sq[0],sq[0]+sq[2]});
            events.push_back({sq[1]+sq[2],-1,sq[0],sq[0]+sq[2]});
            xsset.insert(sq[0]);
            xsset.insert(sq[0]+sq[2]);
        }
        sort(events.begin(),events.end());
        vector<int> xs(xsset.begin(),xsset.end());
        SegmentTree segtr(xs);
        vector<double> psum;
        vector<int> width;
        double total_area=0;
        int prev= get<0>(events[0]); //get 0th element in compile time
        for(auto [y,d,xl,xr]:events){
            int len=segtr.query();
            total_area+= 1ll*len*(y-prev);
            segtr.update(xl,xr,d);
            psum.push_back(total_area);
            width.push_back(segtr.query());
            prev=y;
        }
        ll target=(ll)(total_area+1)/2; //rounded half area
        int i=lower_bound(psum.begin(),psum.end(),target)-psum.begin()-1;
        double ar=psum[i];
        int wid=width[i],height=get<0>(events[i]);
        return height+(total_area-ar*2)/(wid*2.0);
    }
};