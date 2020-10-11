#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    int a,b;
    cin>>a>>b;
    char x[2];
    x[0]=s1[a], x[1]=s1[b];
    s1 = s1.substr(0,a)+s1.substr(a+1, b-a-1)+s1. substr(b+1, n-b-1);
    int i=0, t=0;
    bool check =true;
    for(int j=0; j<n; j++){
        if(i>=n-2 || s1[i]!=s2[j]){
            if(t<2){
                if(s2[j]==x[t]){
                    t++;
                }
                else{
                    check = false;
                    break;
                }
            }
            else{
                check= false;
                break;
            }
        }
        else i++;
    }
    if(check) cout<<"YES";
    else cout<<"NO";
    return 0;
}