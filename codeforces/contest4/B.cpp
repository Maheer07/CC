#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x = 0; x < t; x++){
        int res = -1;
        int a,b,c;
        
        cin>>a>>b>>c;
        int g = a;
        if(b>g) g = b;
        if(c>g) g = c;
        int r = abs(a-b);
        int n = 2*r;

        int m = r+1;
        if(g <= n){
            if(c < m){
                if(c+r <= n){
                    res = c+r;
                }
            }
            else{
                if(c <= n){
                    res = c - r;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}