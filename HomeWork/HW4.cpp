#include<iostream>
using namespace std;

class linklist{
    private:
        int size;
        class node{
            private:
                double exp , coef;
                node *next;
                friend class linklist;
            public:
                node(){
                    double exp;
                    double coef;
                    node *next;
                }     
        };
        node *head;
    public:
        linklist(){
            int size;
        }
        void insert(){
            cout << "Please input the size of the polynomial:" << endl;
            cin >> size;
            node *head = new node[size];
            for(int i = 0; i < size; i++){
                cout << "Please input the coefficient of the polynomial" << i+1 << ":" << endl;
                cin >> head[i].coef ;
                cout << endl << "Please input the exponent of the polynomial" << i+1 << ":" << endl;
                cin >> head[i].exp;
                cout << endl;
            }
            for(int i = 0; i < size; i++){
                head[i].next = &head[i+1];
            }
            head[size-1].next = 0;
        }
        void print(){
            node temp = head[0];
            while(temp.next != 0){
                cout << temp.coef << "x^" << temp.exp ;
                temp = *temp.next;
                if(temp.next != 0){
                    cout << " + ";
                }
            }
            cout << endl;
        }
        void multiply(linklist &a, linklist &b){
            linklist c ;
            c.size = a.size * b.size;
            node *head = new node[c.size];
            for(int i = 0; i < a.size; i++){
                for(int j = 0; j < b.size; j++){
                    head[i * b.size + j].coef = a.head[i].coef * b.head[j].coef;
                    head[i * b.size + j].exp = a.head[i].exp + b.head[j].exp;
                }
            }
            for(int i = 0; i < c.size; i++){
                for(int j = i+1; j < c.size; j++){
                    if(head[i].exp < head[j].exp){
                        node temp = head[i];
                        head[i] = head[j];
                        head[j] = temp;
                    }
                }
            }
            for(int i = 0; i < c.size; i++){
                head[i].next = &head[i+1];
            }
            head[c.size-1].next = 0;
            c.print();

        }
};

int main(){
    linklist a;
    a.insert();
    linklist b;
    b.insert();
    a.multiply(a, b);
    return 0;    
}