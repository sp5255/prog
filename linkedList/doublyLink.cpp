#include<iostream>
using namespace std;

template<typename T>
class doublyList{
    private:
        T data;
        doublyList *head, *tail, *next,*prev, *end;
    public:
        doublyList();
        void push(T );
        void forward();
        void backward();
};

template<typename T>
doublyList<T>::doublyList(){
    head = tail = end = nullptr;
}

template<typename T>
void doublyList<T>::push(T item){
    doublyList *temp = new doublyList;
    if(!head){
        head  = temp;
        head->data = item;
        head->prev = head->next = nullptr;
        tail = head;
    }
    else{
        doublyList *back = tail;
        tail->next = temp;
        tail = temp;
        tail->data = item;
        tail->prev = back;
        tail->next = nullptr;
        end = tail;
    }
}

template<typename T>
void doublyList<T>::forward(){
    doublyList *temp = head;
    while(temp){
        cout<<temp->data;
        temp = temp->next;
        if(temp)
        cout<<" --> ";
    }
}

template<typename T>
void doublyList<T>::backward(){
    doublyList *temp = end;
    while(temp){
        cout<<temp->data;
        temp = temp->prev;
        if(temp )
        cout<<" --> ";
    }
}

int main(){
    doublyList<int> l1;
    l1.push(2);
    l1.push(32);
    l1.push(44);
    l1.push(35);
    l1.push(15);
    l1.push(25);
    l1.push(52);
    l1.push(59);

    cout<<"forward\n";
    l1.forward();
    cout<<"\nbackward\n";
    l1.backward();
    cout<<endl;

    doublyList<string> l2;

    l2.push("one");
    l2.push("two");
    l2.push("three");
    l2.push("four");
    l2.push("five");
    l2.push("six");
    l2.push("seven ");
    l2.push("eight");

    cout<<"forward\n";
    l2.forward();
    cout<<"\nbackward\n";
    l2.backward();
    cout<<endl;

    return 0;
}