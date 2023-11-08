class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int vert_dist = abs(sx-fx);
        int hori_dist = abs(sy-fy);

        if(vert_dist==0 && hori_dist==0 && t==1){
            return false;
        }

        return t>=max(vert_dist, hori_dist);
    }
};