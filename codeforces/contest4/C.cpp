#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x = 0; x < t; x++){
        int n;
        cin>>n;
        int i = 1;
        while(true){
            if(i*i< n)  i++;
            else    break;
        }
        if(i*i==n){
            cout<<i<<" "<<1<<endl;
            
        }
        else
        {   
            int y = i-1;
            int r = n - (y*y);
            //cout<<y<<" "<<r<<endl;
            if(r > y+1){
              //  cout<<1<<endl;
                cout<<y+1<<" "<<2*(y+1)-r<<endl;
            }
            else{
                //cout<<2<<endl;
                cout<<r<<" "<<y+1<<endl;
            }
        }
    }
    return 0;

}