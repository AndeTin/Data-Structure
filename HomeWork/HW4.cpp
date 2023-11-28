#include<iostream>
using namespace std;

class linklist{
    private:
        int size;
        class node{
            private:
                double exp , coef;
                node* next;
                friend class linklist;
            public:
                node(){
                    exp = 0;
                    coef = 0;
                    next = 0;
                }     
        };
        node *head;
    public:
        linklist(){
            size = 0;
            head = 0;
        }
        //set the polynomial
        void insert(){
            cout << "Please input the size of the polynomial:" << endl;
            cin >> size;
            head = new node[size];
            for(int i = 0; i < size; i++){
                cout << "Please input the coefficient of the polynomial " << i+1 << ":" << endl;
                cin >> head[i].coef >> head[i].exp;
                // cin >> head[i].exp;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a number for the coefficient of polynomial " << i+1 << ":" << endl;
                    cin >> head[i].coef ;
                }
                // cout << endl << "Please input the exponent of the polynomial " << i+1 << ":" << endl;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a number for the exponent of polynomial " << i+1 << ":" << endl;
                    cin >> head[i].exp;
                }
                cout << endl;
            }
            for(int i = 0; i < size; i++){
                for(int j = i+1; j < size; j++){
                    if(head[i].exp < head[j].exp){
                        node temp = head[i];
                        head[i] = head[j];
                        head[j] = temp;
                    }
                }
            }
            for(int i = 0; i < size; i++){
                head[i].next = &head[i+1];
            }
            head[size-1].next = 0;
        }
        //multiply the polynomial
        void multiply(linklist &a, linklist &b){
            linklist c ;
            c.size = a.size * b.size;
            c.head = new node[c.size];
            for(int i = 0; i < a.size; i++){
                for(int j = 0; j < b.size; j++){
                    c.head[i*b.size+j].coef = a.head[i].coef * b.head[j].coef;
                    c.head[i*b.size+j].exp = a.head[i].exp + b.head[j].exp;
                }
            }
            cout<< "Calculate finished" << endl;
            //sort the polynomial
            for(int i = 0; i<c.size; i++){
                for (int j = i+1; j < c.size; j++){
                    if(c.head[i].exp < c.head[j].exp){
                        node temp = c.head[i];
                        c.head[i] = c.head[j];
                        c.head[j] = temp;
                    }
                }
            }
            cout << "Sort finished" << endl;
            //set the next pointer
            for(int i = 0; i < c.size; i++){
                if(i == c.size-1)
                    c.head[i].next = 0;
                else
                    c.head[i].next = &c.head[i+1];
            }
            cout << "Set next pointer finished" << endl;
            //simplify the polynomial
            cout << "Begin to simplify the polynomial:" << endl;
            int count = 0;
            node *test = c.head;
            for(int i = 0 ; i < c.size; i++){
                if(test->exp == c.head[i+1].exp){
                    test->coef += c.head[i+1].coef;
                    test->next = c.head[i+1].next;
                    c.head[i+1].coef = 0;
                    count++;
                }
                else{
                    test = test->next;
                }

            }
            //print the result
            cout << "The result of the multiplication is:" << endl;
            for(int i = 0; i < c.size; i++){
                if(c.head[i].coef != 0 && c.head[i].exp != 0){
                    cout << c.head[i].coef << "x^" << c.head[i].exp;
                }
                if(i != c.size-1 && c.head[i+1].coef != 0 && c.head[i+1].exp != 0){
                    cout << " + ";
                }
            }
            cout << endl;
            //free the memory
            free(&c);
        }
};

int main(){
    linklist a;
    a.insert();
    linklist b;
    b.insert();
    a.multiply(a, b);
    free(&a);
    free(&b);
    return 0;    
}