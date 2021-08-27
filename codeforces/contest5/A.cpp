#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int i){
    int temp = v[i+1];
    v[i+1] = v[i];
    v[i] = temp;

}

bool f(vector<int> &v, int i){
    if(v[i] > v[i+1]){
        swap(v,i);
        return true;
    }
    else    return false;
}

void printvec(vector<int> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int x = 0; x < t; x++){
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int d;
            cin>>d;
            v.push_back(d);
        }
        int res = 0;
        int same = 0;
        int i = 0;
        while(true){
            bool changed = false;
            
            if(i%2 == 1){
                int j = 1;
                while(j <= n-2){
                    if(f(v,j))    changed = true;
                    j+=2;
                }
            }
            else{
                int j = 0;
                while(j <= n-3){
                    if(f(v,j))    changed = true;
                    j+=2;
                }                
            }
            
            //cout<<changed<<endl;
            if(changed == false){    same++;
            }
            else{
                res++;
                if(same > 0)
                {
                    same = 0;
                    res++;
                }
            }
            i++;
            if(same == 2)   break;
            //printvec(v);
            
        }   
        cout<<res<<endl;

    }
    return 0;
}