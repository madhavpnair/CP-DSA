class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        for(int i=0; i<k+1; i++){
            vector<int> temp = dist;
            for(auto e : flights){
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                // updated values not to be used in this iteration
                // o.w stop constraints get violated 
                if(dist[u]!=INT_MAX and dist[u] + wt < temp[v]){
                    temp[v] = dist[u] + wt;
                }
            }
            dist = temp;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
