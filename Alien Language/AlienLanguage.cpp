/**
** Problem: https://code.google.com/codejam/contest/90101/dashboard#s=p0
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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
#include <functional>
using namespace std;
#define LOOP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define LOOPE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LOOPR(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB(item) push_back(item)
#define MP(item1,item2) make_pair((item1),(item2))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define ULL unsigned long long int
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef list<pair<int,int> > LPII;
typedef vector<list<pair<int,int> > > VLPII;
typedef unordered_map<int,int> UMII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }

template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}
template<class T1,class T2,class T3,class T4> void DEBUG(T1 e1, T2 e2, T3 e3, T4 e4){    cout << e1 << ", " << e2 << ", " << e3 << ", " << e4 << endl;}

int main(){

    ifstream in("A-large-practice.in");
    ofstream out("output-large.txt");

    int L,D,N,Case=0;
    in>>L>>D>>N;
    vector<string> set;
    string s;
    while(D--){
        in>>s;
        set.PB(s);
    }
    while(N--){
        Case++;
        in>>s;
        vector<string> vs;
        LOOPL(i,0,s.length()){
            if(s[i]=='('){
                int current=i+1;
                while(s[i]!=')') i++;
                vs.PB(s.substr(current,i-current));
            }else{
                vs.PB(s.substr(i,1));
            }
        }
        LOOP(i,vs.size()) sort(ALL(vs[i]));
        int count=0;
        LOOP(i,set.size()){
            bool found=true;
            LOOP(j,vs.size()){
                if(!binary_search(ALL(vs[j]),set[i][j])){
                    found=false;
                    break;
                }
            }
            if(found) count++;
        }
        static ULL progress=0;
        cout<<progress<<'\r'<<flush;
        progress++;
        out<<"Case #"<<Case<<": "<<count<<endl;
    }

    return 0;
}
