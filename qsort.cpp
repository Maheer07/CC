#include<bits/stdc++.h>
using namespace std;


void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(vector<int> &v, int l, int h){
    int pivot = v[h];
    //cout<<"Pivot "<<pivot<<endl;
    int i = l-1;
    
    for(int j = l; j < h; j++){
        //cout<<v[j]<<endl;
        if(v[j] < pivot){
            i++;
            swap(&v[i],&v[j]);   
        }
    }
    swap(&v[i+1],&v[h]);
    return i+1;
}



void qsort(vector<int> &v, int l, int h){
    if (l < h){
        int p = partition(v,l,h);
        //cout<<"partition "<<p<<endl;
        qsort(v,l,p-1);
        qsort(v,p+1,h);
    }
}


int main(){

    int a[6] = {7,4,2,5,1,6};
    //qsort(a,0,5);
    vector<int> v = {7,4,2,5,1,6};
    qsort(v,0,5);

    for(int i = 0; i < 6; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}