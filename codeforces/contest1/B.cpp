#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z = 0; z < t; z++){
        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;
        string s1;
        string s2;
        cin>>s1>>s2;
        for(int j = 0;j < n; j++){
            if(s1[j] == '0')    a.push_back(0);
            else    a.push_back(1);
        }
        for(int j = 0;j < n; j++){
            if(s2[j] == '0')    b.push_back(0);
            else    b.push_back(1);
        }     
        int res = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == 1){
                if(a[i] == 0){
                    a[i] = -1;
                    res++;
                }
                else if(i!=0 && a[i-1] == 1){
                    a[i-1] = -1;
                    res++;
                }
                else if(i!= n-1 && a[i+1] == 1){
                    a[i+1] = -1;
                    res++;
                }
            }
        }   
        cout<<res<<endl;
    }
    return 0;
}