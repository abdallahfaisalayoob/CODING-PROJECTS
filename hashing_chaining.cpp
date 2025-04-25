#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Hash
{
    list<int> *H;
    int size;
public:
    Hash(int s){
        H= new list<int>[s]; size=s; }
    void insert(int);
    bool search(int);
};



int main(){

    Hash hobj(45);
    hobj.insert(23);
    hobj.insert(44);
    hobj.insert(2);
    hobj.insert(73);
    hobj.insert(34);
    hobj.insert(63);
    hobj.insert(99);
    if(hobj.search(34))
        cout<<"found";
    else
        cout<<"not found";
}

void Hash::insert(int num){
    int index=num%size;  // int
    H[index].push_front(num);
}

bool Hash::search(int x){
    int index=x%size;

    auto it = H[index].begin();

    for(;it!=H[index].end();it++)
        if(*it == x)
            return true;
    return false;
}
