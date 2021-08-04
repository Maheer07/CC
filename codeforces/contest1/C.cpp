#include<bits/stdc++.h>
using namespace std;

void calc_nobles(int n,unordered_map<int,bool> alive, map<int,vector<int>> friends,
unordered_map<int,int> lowest,vector<int> nobles){
    for(int i = 1; i <= n; i++){
        if(alive[i]){
            if(lowest.find(i) != lowest.end()){
                if(lowest[i] > i)   nobles[i] = 1;
            }
        }
    }

}


int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,bool> alive;
    for(int i = 1; i <= n; i++){
        alive[i] = true;
    }
    unordered_map<int,int> lowest;
    map<int,vector<int>> friends;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        if(lowest.find(a) == lowest.end()){
            vector<int> temp;
            temp.push_back(b);
            friends[a] = temp;
            lowest[a] = b;
        }
        else{
            if(lowest[a] > b)   lowest[a] = b;
            friends[a].push_back(b);
        }
        if(lowest.find(b) == lowest.end()){
            vector<int> temp;
            temp.push_back(a);
            friends[b] = temp;
            lowest[b] = a;
        }
        else{
            if(lowest[b] > a)   lowest[b] = a;
            friends[b].push_back(a);
        }        
    }
    vector<int> nobles;
    for(int i = 0; i < n+1;i++){
        nobles[i] = 0;
    }
    calc_nobles(n,alive,friends,lowest,nobles);
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        int f;
        cin>>f;
        if(f == 1){
            int a, b;
            cin>>a>>b;
            if(lowest.find(a) == lowest.end()){
                vector<int> temp;
                temp.push_back(b);
                friends[a] = temp;
                lowest[a] = b;
            }
            else{
                if(lowest[a] > b)   lowest[a] = b;
                friends[a].push_back(b);
            }
            if(lowest.find(b) == lowest.end()){
                vector<int> temp;
                temp.push_back(a);
                friends[b] = temp;
                lowest[b] = a;
            }
            else{
                if(lowest[b] > a)   lowest[b] = a;
                friends[b].push_back(a);
            }
            calc_nobles(n,alive,friends,lowest,nobles);
        }
        else if(f == 2){
            int a,b;
            cin>>a>>b;
            


        }
        else if(f == 3){

        }
    }

    return 0;
}