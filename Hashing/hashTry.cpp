#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    int x[] = {28,39,294,41,23,25};
    int s = sizeof(x)/sizeof(int);
    //int hash[s] = {0};
    vector<int> hash;
    for(int el:x){
        int p = el%10;
       hash[p] = el;
    }
    cout<<"hash\n";
    for(int el:hash){
        cout<<el<<"\t";
    }
    cout<<endl;
    return 0;
}