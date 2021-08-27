#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int m = 0;
    vector<int> v;
    for(int x = 0; x < t; x++){
        int a;
        cin>>a;
        v.push_back(a);
        if(a > m)   m = a;
    }
    int i = 1;
    vector<int> q;
    while(true){
        if(i % 3  == 0 || i % 10 == 3){
            i++;
        }
        else{
            q.push_back(i);
            i++;
        }
        int n = q.size();
        if(n == m){
            break;
        }
    }

    cout<<endl;
    for(int i = 0; i < t; i++){
        cout<<q[v[i]-1]<<endl;
    }
    return 0;
}