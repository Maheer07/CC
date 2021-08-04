#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> &v, int l)
{
    int result = v[0];
    for (int i = 1; i < l; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}


int main(){
    int t;
    cin>>t;

    for(int i = 0; i < n; i++){
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int t;
            cin>>t;
            v.push_back(t);
            vector<int> diff;
            for(int i = 0; i < n-1; i++){
                int d = v[i] - v[i-1];
                diff.push_back(abs(d));
            }
            int m = 0;
            for(int i = 0; i < n; i++){
                
            }

        }
    }
}