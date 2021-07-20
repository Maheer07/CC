#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "acdsces";
    unordered_set<char> s1;
    unordered_set<char> r;
    unordered_map<char,bool> m;
    unordered_map<char,char> last;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s1.find(s[i]) == s1.end()){
            s1.insert(s[i]);
        }
        else{
            r.insert(s[i]);
            m[s[i]] = false;
        }
    }
    
    map<char, set<char>> prev;
    map<char, set<char>> next;
    
    list<char> l;
    
    for(int i = 0; i < n; i++){
        if(r.find(s[i]) == r.end()){
            l.push_back(s[i]);
            cout<<s[i];
        }

    }
    cout<<endl;
    auto it = l.begin();
    int ind = 0;
    
    while(ind < n){
        set<char> t;
        while(s[ind] != *it){
            
            t.insert(s[ind]);
            last[s[ind]] = *it;
            ind++;   
        }
        prev[*it] = t;
        cout<<"Prev "<<*it<<" ";
        for(auto k = t.begin();k!= t.end();++k){
            cout<<*k;
        }
        cout<<endl;
        ind++;
        if(*it == l.back()){
            set<char> x;
            while(ind < n){
                x.insert(s[ind]);
                last[s[ind]] = '9';
                ind++;
                
            }
            next[*it] = x;
            
            cout<<"Next "<<*it<<" ";
            for(auto k = x.begin();k!= x.end();++k){
                cout<<*k;
            }
            cout<<endl;            
            }
        else{
            ++it;
        }
    }

    
    string res = "";
    for(auto it = l.begin(); it != l.end(); ++it){
        for(auto itr = prev[*it].begin();itr != prev[*it].end();++itr){
            if(*itr < *it  && !m[*itr]){
                res += *itr;
                m[*itr] = true;
            }
            else if(!m[*itr] && last[*itr] == *it){
                res += *itr;
                cout<<*itr<<endl;
                m[*itr] = true;                
            }
        }
        res += *it;
        if(*it == l.back()){
            for(auto j = next[*it].begin(); j != next[*it].end();++j){
                if(!m[*j]){
                    res += *j;
                    m[*j] = true;
                }
            }
        }
    }
    cout<<"Answer "<<res<<endl;

    return 0;
}