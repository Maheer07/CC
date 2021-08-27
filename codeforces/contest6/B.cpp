#include<bits/stdc++.h>
using namespace std;

bool iscomp(int n){
    if(n == 2)  return false;
    if(n == 1 || n == 0 || (n %2 == 0))  return true;
    for(int i = 3; i*2 <= n; i+=2){
        if(n % i == 0)  return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    vector<int> p;
    vector<int>q;
    for(int x = 0; x < t; x++){
        int n;
        cin>>n;
        vector<int> a;
        string d;
        cin>>d;
        bool found = false;
        for(int i = 0; i < n; i++){
            a.push_back(d[i] - '0');
        }

        if(!found){
            for(int i = 0; i < n; i++){
                if(iscomp(a[i])){
                    found = true;
                    p.push_back(1);
                    q.push_back(a[i]);

                    break;
                }
            }
        }
        if(!found){
            for(int i = 0; i < n-1; i++){
                if(!found){
                    for(int j = i+1; j < n; j++){
                        int t = a[i] * 10 + a[j];
                        if(iscomp(t)){
                            found = true;
                            p.push_back(2);
                            q.push_back(t);
                            break;
                        }
                    }
                }
                else    break;
            }
        }
    }
    int h = p.size();
    for(int i = 0; i < h;i++){
        cout<<p[i]<<endl;
        cout<<q[i]<<endl;
    }
    return 0;
}