#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int p;
        cin>>p;
        unordered_map<int,int> r;
        for(int j = 2; j < p; j++){
            int x = p % j;
            if(r.find(x) == r.end()){
                r[x] = j;
            }
            else{
                cout<<r[x]<<" "<<j<<endl;
                break;
            }
        }

    }

    return 0;
}