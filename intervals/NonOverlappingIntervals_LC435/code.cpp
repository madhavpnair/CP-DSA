#include <bits/stdc++.h>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)return 0;
        vector<vector<int>> selected;
        sort(intervals.begin(), intervals.end(),
           [](vector<int>&a, vector<int>&b) {
                return a[1]<b[1];
            });
        selected.push_back(intervals[0]);
        for(int i=0; i<n; i++){
            if(selected.back()[1] <= intervals[i][0])selected.push_back(intervals[i]);
        }
        return n - selected.size();
    }
};