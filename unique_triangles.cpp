#include<bits/stdc++.h>
using namespace std;

map<vector<long long int>,bool> m;

int count(vector<vector<long long int>> &v){
    int res = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        sort(v[i].begin(),v[i].end());
        if(m.find(v[i]) != m.end()){
            m[v[i]] = false;
        }
        else{
            m[v[i]] = true;
        }
    }

    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second)   res++;
    }
    return res;

}

int main(){
    int n;
    cin>>n;
    vector<vector<long long int>> v;
    for(int i = 0; i < n; i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        vector<long long int> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        v.push_back(t);
    }
    cout<<count(v)<<endl;

}