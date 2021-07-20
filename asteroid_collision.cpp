#include <bits/stdc++.h>
using namespace std;

int main(){
        vector<int> asteroids = {5,10,-5};
        deque<int> q;
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
            if(q.empty()){
                q.push_back(asteroids[i]);
            }
            else{
                q.push_back(asteroids[i]);
                while(true){
                    if(q.empty()){
                        break;
                    }
                    int a = q.back();
                    q.pop_back();
                    int b = q.back();
                    q.pop_back();                    
                    if(a*b > 0){
                        q.push_back(b);
                        q.push_back(a);
                        break;
                    }
                    else{
                        if(abs(a) > abs(b)){
                            q.push_back(a);
                        }
                        else if(abs(b) > abs(a)){
                            q.push_back(b);
                        }                     
                    }
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop_front();
        }
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<endl;
        }

    return 0;
}