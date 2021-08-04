#include<bits/stdc++.h>
using namespace std;


bool mycomp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),mycomp);
    
    int m =0;
    int n = intervals.size();

    
    
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < n; i++){
        if(res[m][1] >= intervals[i][0]){
            res[m][1] = max(res[m][1], intervals[i][1]);
            
        }
        else{
            m++;
            res.push_back(intervals[i]);
        }
    }        
    return res;           
}



int main(){

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    int n = ans.size();
    for(int i = 0; i < n; i++){
        cout<<ans[i][0]<<"\t"<<ans[i][1]<<endl;
    }

    return 0;
}