#include <bits/stdc++.h>
using namespace std;

int main(){

vector<string> tokens = {"4","13","5","/","+"};
stack<int>s;
int n = tokens.size();
for(int i = 0; i < n; i++){
    if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
        s.push(stoi(tokens[i]));
    }
    else if(tokens[i] == "+"){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a+b);
    }
    else if(tokens[i] == "-"){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b-a);
    }
    else if(tokens[i] == "*"){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a*b);
    }
    else if(tokens[i] == "/"){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b/a);
        
    }            
}
cout<< s.top()<<endl;
return 0;

}