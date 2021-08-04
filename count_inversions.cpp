#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &a, int l, int mid,int h){
    int res = 0;
    int n1 = mid - l+1;
    int n2 = h - mid;
    vector<int> t1;
    vector<int> t2;
    for(int i = 0; i < n1; i++){
        t1.push_back(a[l+i]);
    }
    for(int i = 0; i < n2; i++){
        t2.push_back(a[mid+1+i]);
    }

    int ind = l;
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(t1[i] < t2[j]){
            //a[ind] = t1[i];
            i++;
  //          ind++;
        }
        else{
            //a[ind] = t2[j];
            j++;
    //        ind++;
            res += n1 - i; 
        }
    }
    // while(i < n1){
    //    //a[ind] = t1[i];
    //     ind++;
    //     i++;
    // }
    // while(j < n2){
    //    //a[ind] = t2[j];
    //     ind++;
    //     j++;
    // }
    return res;

}

int mergesort(vector<int> &a, vector<int> &temp, int l, int h){
    int res = 0;
    if(l < h){
        int mid = (l+h) / 2;
        res += mergesort(a,temp,l,mid);
        res += mergesort(a,temp,mid+1,h);
        res += merge(a,l,mid,h);
    }
    return res;


}


int countInversions(vector<int> &a){
    int n = a.size();
    vector<int> temp;
    int x = mergesort(a,temp,0,n-1);
    return x;
}


int main(){
    vector<int> a = {1,20,6,4,5};
    cout<<countInversions(a)<<endl;
    int n = a.size();
    for(int i = 0; i < n; i++){
        cout<<a[i]<<"\t";
        
    }
    cout<<endl;
    return 0;
}