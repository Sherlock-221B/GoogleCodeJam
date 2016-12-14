/**
** Problem: https://code.google.com/codejam/contest/90101/dashboard#s=p1
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


#define ITSELF   0
#define UP       1
#define DOWN     2
#define LEFT     3
#define RIGHT    4
int H,W;
void DFS(vector<vector< bool> > &visited, char letter,VVI sink,int i, int j, vector<vector<char> > &output){
    visited[i][j]=true;
    output[i][j]=letter;
    
    switch(sink[i][j]){
        case ITSELF:break;
        case UP: if(i>0 && !visited[i-1][j]) DFS(visited,letter,sink,i-1,j,output); break;
        case LEFT: if(j>0 && !visited[i][j-1]) DFS(visited,letter,sink,i,j-1,output); break;
        case RIGHT: if(j<W-1 && !visited[i][j+1]) DFS(visited,letter,sink,i,j+1,output); break;
        case DOWN: if(i<H-1 && !visited[i+1][j]) DFS(visited,letter,sink,i+1,j,output); break;
    }
    if(i>0 && sink[i-1][j]==DOWN && !visited[i-1][j]) DFS(visited,letter,sink,i-1,j,output);
    if(j>0 && sink[i][j-1]==RIGHT && !visited[i][j-1]) DFS(visited,letter,sink,i,j-1,output);
    if(j<W-1 && sink[i][j+1]==LEFT && !visited[i][j+1]) DFS(visited,letter,sink,i,j+1,output);
    if(i<H-1 && sink[i+1][j]==UP && !visited[i+1][j]) DFS(visited,letter,sink,i+1,j,output);
}

int main(){

    ifstream fin("B-large-practice.in");
    ofstream fout("output-large.txt");

    int T,Case=0;
    fin>>T;
    while(T--){
        Case++;
        fin>>H>>W;
        VVI map(H,VI(W));
        LOOP(i,0,H-1){
            LOOP(j,0,W-1){
                fin>>map[i][j];
            }
        }
        VVI sink(H,VI(W));
        LOOP(i,0,H-1){
            LOOP(j,0,W-1){
                sink[i][j]=ITSELF;
                int min=map[i][j];
                if(i>0 && map[i-1][j]<min){
                    min=map[i-1][j];
                    sink[i][j]=UP;
                }
                if(j>0 && map[i][j-1]<min){
                    min=map[i][j-1];
                    sink[i][j]=LEFT;
                }
                if(j<W-1 && map[i][j+1]<min){
                    min=map[i][j+1];
                    sink[i][j]=RIGHT;
                }
                if(i<H-1 && map[i+1][j]<min){
                    sink[i][j]=DOWN;
                }
            }
        }
        vector<vector< bool> > visited(H, vector<bool>(W,false));
        vector<vector<char> > output(H,vector<char>(W));
        char letter='a';
        LOOP(i,0,H-1){
            LOOP(j,0,W-1){
                if(!visited[i][j]){
                    DFS(visited,letter,sink,i,j,output);
                    letter++;
                }
            }
        }
        fout<<"Case #"<<Case<<":"<<endl;
        LOOP(i,0,H-1){
            LOOP(j,0,W-1){
                fout<<output[i][j]<<" ";
            }
            fout<<endl;
        }
    }
    return 0;
}
