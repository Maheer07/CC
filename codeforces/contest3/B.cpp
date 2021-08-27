#include <bits/stdc++.h>
using namespace std;


int calcl(int x, string s){
    int res = 0;
    for(int i = x-1; i >=0; i--){
        if(s[i]==s[i+1])    res++;
        else break;
    }
    return res;
}
int calcr(int x, string s, int n){
    int res = 0;
    for(int i = x+1; i<n; i++){
        if(s[i]==s[i-1])    res++;
        else break;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    vector<string> ans;
    for(int x = 0; x < t; x++){
        int m;
        cin>>m;
        string s;
        cin>>s;
        vector<int> v;
        for(int i = 0; i < m;i++){
            if(s[i] == '?') v.push_back(i);
        }
        int n = v.size();
        for(int i = 0; i < n; i++){
            int ind = v[i];
            if(s[ind] == '?'){
                if(ind == 0){
                    if(s[1] == 'R') s[0] = 'B';
                    else if(s[1] == 'B')    s[0] = 'R';
                    else{
                        int z = ind;
                        while(s[z] == '?'){
                            z++;
                        }
                        if(z==n){
                            s[0] = 'B';
                            for(int j= 1; j < m; j++){
                                if(s[j-1]=='B') s[j] = 'R';
                                else if(s[j-1] == 'R')  s[j] = 'B';
                            }
                        }
                        else{
                            while(z != ind){
                                if(s[z] == 'B') s[z-1] = 'R';
                                else if(s[z] == 'R')    s[z-1] = 'B';
                                z--;
                            }
                        }
                    }
                }
                else if(ind == m-1){
                    if(s[m-2] == 'R') s[m-1] = 'B';
                    else if(s[m-2] == 'B')    s[m-1] = 'R';
                }
                else{
                    if(s[ind-1] == 'R'){
                        if(s[ind+1] == 'R')   s[ind] = 'B';
                        else if(s[ind+1] == 'B'){
                            int a = calcl(i-1,s);
                            int b = calcr(i+1,s,m);
                            if(a<b) s[ind] = 'R';
                            else    s[ind] = 'B';
                        }
                        else{
                            int z = ind;
                            while(s[z] == '?'){
                                z++;
                            }
                            if(z==n){
                                s[ind] = 'B';
                                for(int j= ind+1; j < m; j++){
                                    if(s[j-1]=='B') s[j] = 'R';
                                    else if(s[j-1] == 'R')  s[j] = 'B';
                                }
                            }
                            else{
                                int a = calcl(ind-1,s);
                                int b = calcr(z,s,m);
                                if(a < b){
                                    s[ind] = 'R';
                                    for(int k = ind+1; k < z; k++){
                                        if(s[k-1] == 'R')   s[k] = 'B';
                                        else if(s[k-1] == 'B')  s[k] = 'R';
                                    }
                                }
                                else{
                                    s[z-1] = s[z];
                                    for(int k = z-2;k>=ind;k--){
                                        if(s[k+1] == 'R')   s[k] = 'B';
                                        else if(s[k+1] =='B')   s[k] = 'R';
                                    }

                                }

                            }                            
                        }
                    }
                    else if(s[ind-1] == 'B'){
                        if(s[ind+1] == 'B')   s[ind] = 'R';
                        else if(s[ind+1] == 'R'){
                            int a = calcl(i-1,s);
                            int b = calcr(i+1,s,m);
                            if(a<b) s[ind] = 'B';
                            else    s[ind] = 'R';
                        }
                        else{
                            int z = ind;
                            while(s[z] == '?'){
                                z++;
                            }
                            if(z==n){
                                s[ind] = 'R';
                                for(int j= ind+1; j < m; j++){
                                    if(s[j-1]=='B') s[j] = 'R';
                                    else if(s[j-1] == 'R')  s[j] = 'B';
                                }
                            }
                            else{
                                int a = calcl(ind-1,s);
                                int b = calcr(z,s,m);
                                if(a < b){
                                    s[ind] = 'B';
                                    for(int k = ind+1; k < z; k++){
                                        if(s[k-1] == 'R')   s[k] = 'B';
                                        else if(s[k-1] == 'B')  s[k] = 'R';
                                    }
                                }
                                else{
                                    s[z-1] = s[z];
                                    for(int k = z-2;k>=ind;k--){
                                        if(s[k+1] == 'R')   s[k] = 'B';
                                        else if(s[k+1] =='B')   s[k] = 'R';
                                    }

                                }

                            }                            
                        }


                    }

                }
            }
        }
        ans.push_back(s);
    }
    int f = ans.size();
    for(int i = 0; i < f; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}





