#include<iostream>
#include<vector>
#include<string>
using namespace std;

//ADDED from windows

int main(){



    string s="/VIJAY/JADHAV/RAMESH";
    vector<string> v;
    split(v,s);
    for(int i=0;i<v.size();i++) cout<<v[i]<<endl;


    return 0;
}