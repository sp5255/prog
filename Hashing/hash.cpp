#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Hash{
    private:
        int value;
        vector<list<int>> bucket;
    public:
        Hash(int);                              //constructor
        int hashFunction(int);                  
        void insert(int);
        void deleteElement(int);
        void print();
};

Hash::Hash(int size){
    bucket.resize( size);
}


// hash function
inline int Hash:: hashFunction(int value){
    return value % bucket.size();
}

// insert in the hastable i,e, bucket
void Hash:: insert(int value){
    int ind = hashFunction(value);
    bucket[ind].push_back(value) ;
}



void Hash::print(){
    list<int> :: iterator j;
  for(int i = 0; i < bucket.size(); i++){
      cout<<i<<" = ";
      for(j = bucket[i].begin(); j !=  bucket[i].end(); j++){
          cout<<*j<<" --> ";
      }
      cout<<endl;
  }
}

/* void Hash::deleteElement(int key){
    for(int i  = 0; i < bucket.size(); i++){
        for(auto j = bucket.begin(); j != bucket.end(); j++)
    }

} */

int main(){
    Hash h1(13);

    h1.insert(6);
    h1.insert(7);
    h1.insert(39);
    h1.insert(75);
    h1.insert(5);      
    h1.insert(246);
    h1.insert(131);

    cout<<"bucket\n";
    h1.print();

    return 0;
}
