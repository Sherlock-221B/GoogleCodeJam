/**
** Problem: https://code.google.com/codejam/contest/90101/dashboard#s=p2
**/
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

void compute(int &count, string &s,int sindex,int slen,string &t, int tindex, int tlen){
    if(tindex==tlen){
        count=(++count)%10000;
        return;
    }
    LOOP(i,sindex,slen-1){
        if(s[i]==t[tindex]) compute(count,s,i+1,slen,t,tindex+1,tlen);
    }
}


int main(){

    ifstream fin("C-large-practice.in");
    ofstream fout("output-large.txt");

    int T,Case=0;
    fin>>T;
    string dummy;
    getline(fin,dummy); //to ignore empty line after T
    while(T--){
        Case++;
        string s,t="welcome to code jam";
        getline(fin,s);
        int count=0;
        compute(count,s,0,s.length(),t,0,t.length());
        fout<<"Case #"<<Case<<": "<<setw(4)<<setfill('0')<<count<<endl;
    }
    return 0;
}
