#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    pair<long long, long long> p[n];
    long long a,b;
    for(long long i=0; i<n; i++){
        cin>> a>> b;
        p[i] = {a,b};        
    }
    pair<long long, long long> c;
    cin>>a>>b;
    c = {a,b};
    bool ans = true;
    bool check = false;

    // north
    for(long long i=0; i<n; i++){
        if(abs(p[i].x-c.x) - p[i].y + c.y >0) {}
        else check = true;
    }
    if(!check) ans = false;
    check = false;
    // south
    for(long long i=0; i<n; i++){
        if(abs(p[i].x-c.x) +p[i].y - c.y >0) {}
        else check = true;
    }
    if(!check) ans = false;
    check = false;
    // east
    for(long long i=0; i<n; i++){
        if(abs(p[i].y-c.y) + p[i].x - c.x >0) {}
        else check = true;
    }
    if(!check) ans = false;
    check = false;
    for(long long i=0; i<n; i++){
        if(abs(p[i].y-c.y) - p[i].x + c.x >0) {}
        else check = true;
    }
    if(!check) ans = false;
    check = false;
    if(ans) cout<<"NO";
    else cout<<"YES";
    return 0;
}