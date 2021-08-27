#include<bits/stdc++.h>
using namespace std;

int minpower(vector<int> v){
    int ind = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] > v[ind])   ind = i;
    }

    return v[ind] - (ind - 1);
}

int pend(vector<int> v){
    int n = v.size();
    return minpower(v) + n;
}

int main(){
    int t;
    cin>>t;
    map<int,vector<vector<int>>> m;
    for(int x = 0; x < t; x++){
        int c;
        cin>>c;
        vector<vector<int>> caves;
        vector<int> pmin;
        for(int i = 0; i < c; i++){
            int n;
            cin>>n;
            vector<int> temp;
            for(int j = 0; j < c; j++){
                int k;
                cin>>k;
                temp.push_back(k);
                int h = minpower(temp);
                pmin.push_back(h);
                if(m.find(h) != m.end()){
                    m[h].push_back(temp);
                }
                else{
                    vector<vector<int>> g;
                    g.push_back(temp);
                    m[h] = g;
                }
            }
            caves.push_back(temp);
        }
        sort(pmin.begin(),pmin.end());
        vector<vector<int>> caves_sorted;
        for(auto i : m){
            vector<vector<int>> temp = i.second;
            int n = temp.size();
            for(int i = 0; i < n; i++){
                caves_sorted.push_back(temp[i]);
            }
        }
        int i = 0;
        int p = pend(caves_sorted[i]);
        while(true){
            cout<<p<<endl;
            if (p > pmin[i+1]){
                p = pend(caves_sorted[i+1]);
                i++;
            }
            else{
                i = 0;
                p = pmin[i+1];
            }
            //i++;
            if(i==c-1)    break;
        }
        cout<<p<<endl;
    }
}