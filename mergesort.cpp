#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &v, int l, int m, int h){
    vector<int> a;
    vector<int> b;
    int n1 = m-l+1;
    int n2 = h-m;
    for(int i = 0; i < n1; i++){
        a.push_back(v[i+l]);
    }
    for(int i = 0; i < n2; i++){
        b.push_back(v[m+1+i]);
    }
    int x1 = 0;
    int x2 = 0;
    int ind = l;
    while(x1 < n1 && x2 < n2){
        if(a[x1] < b[x2]){
            v[ind] = a[x1];
            x1++;
            ind++;
        }
        else{
            v[ind] = b[x2];
            x2++;
            ind++;
        }
    }
    while(x1 < n1){
        v[ind] = a[x1];
        x1++;
        ind++;
    }

    while(x2 < n2){
        v[ind] = b[x2];
        x2++;
        ind++;
    }    

}


void mergesort(vector<int> &v, int l, int h){
    if(l < h){
        int m = l + (h-l) / 2;
        mergesort(v,l,m);
        mergesort(v,m+1,h);
        merge(v,l,m,h);
    }
}


int main(){

    vector<int> v = {4,7,3,5,1,2};
    mergesort(v,0,5);
    for(int i = 0; i < 6; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;

}