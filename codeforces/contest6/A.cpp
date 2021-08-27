#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x = 0; x < t; x++){
        int l,r;
        cin>>l>>r;
        int res = 0;
        int d = r/2 + 1;
        if(d >= l){
            res = r % d;            
        }
        else    res = r % l;
        cout<<res<<endl;
    }
    return 0;
}