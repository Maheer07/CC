#include<bits/stdc++.h>
using namespace std;




int bsearch(vector<int> v, int a){
    int lo = 0;
    int hi = v.size() - 1;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2 ;
        if(v[mid] == a){
            return mid;
        }
        else if(v[mid] > a){
            hi = mid -1 ;
        }
        else{
            lo = mid + 1;
        }
    }
    return - 1;
}


int main(){
    vector<int> a = {1,3,5,7,9};
    int res = bsearch(a,4);
    cout<<res<<endl;
}