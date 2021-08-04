#include<bits/stdc++.h>


bool helper(vector<vector<int>> &m, int i, int j, int n, vector<string> &s){
    cout<<i <<"\t"<<j<<endl;
    if(i == n-1 && j == n-1){
        s.push_back("");
        return true;
    }
    else if(m[i][j] == 0)   return false;
    else if(i != 0){
        if(helper(m,i-1,j,n,s)){
            int x = s.size();
            for(int k = 0; k < x; k++){
                s[k] = "U" + s[k];
            }
            return true;
        }
    }
    else if(j != 0){
        if(helper(m,i,j-1,n,s)){
            int x = s.size();
            for(int k = 0; k < x; k++){
                s[k] = "L" + s[k];
            }
            return true;
        }
    }
    else if(i != n-1){
        if(helper(m,i+1,j,n,s)){
            int x = s.size();
            for(int k = 0; k < x; k++){
                s[k] = "D" + s[k];
            }
            return true;
        }
    }
    else if(j != n-1){
        if(helper(m,i,j+1,n,s)){
            int x = s.size();
            for(int k = 0; k < x; k++){
                s[k] = "R" + s[k];
            }
            return true;
        }
    }
    return false;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> res;
    if(helper(m,0,0,n,res)){
        return res;
    }
    else{
        vector<string> v;
        return v;
    }
}


int main(){

    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}};
    vector<string> s = findPath(m,4);
    for(int i = 0; i < s.size(); i++){
        cout<<s[i]<<endl;
    }

    return 0;
}