#include<iostream>

using namespace std;

class Complex {
    private:
        float r;
        float i;
    public:

        Complex(float i1 = 0 , float i2 = 0 ){
            r = i1;
            i = i2;
        }

        Complex operator+(const Complex &c){
            float a = r + c.r;
            float b = i + c.i;
            return Complex(a,b);
        }
        Complex operator*(const Complex &c){
            float a = r*c.r - i*c.i;
            float b = r*c.i + i*c.r;
            return Complex(a,b);
        }
        friend istream& operator>>(istream &in, Complex &c){
            in >> c.r >> c.i;
            return in;
        }

        
        friend ostream& operator<<(ostream &out, const Complex &c){
            out << c.r <<" + "<< c.i <<"i";
            return out;
        }
     
};

int main(){
    Complex c1(3,2);
    Complex c2;
    cout<<"Please enter first real number and imaginary number: "<<endl;
    Complex c3;
    cin >> c3;
    cout << "Please enter second real number and imaginary number: "<<endl;
    Complex c4;
    cin >> c4;
    cout <<endl;
    cout <<"SUMs:"<<endl;
    cout <<"c1 + c2 = " << c1+c2<<endl;
    cout << "c1 + c3 = " << c1+c3<<endl;
    cout << "c1 + c4 = " << c1+c4<<endl;
    cout << "c2 + c3 = " << c2+c3<<endl;
    cout << "c2 + c4 = " << c2+c4<<endl;
    cout << "c3 + c4 = " << c3+c4<<endl<<endl;
    cout <<"Products:"<<endl;
    cout << "c1 * c2 = " << c1*c2<<endl;
    cout << "c1 * c3 = " << c1*c3<<endl;
    cout << "c1 * c4 = " << c1*c4<<endl;
    cout << "c2 * c3 = " << c2*c3<<endl;
    cout << "c2 * c4 = " << c2*c4<<endl;
    cout << "c3 * c4 = " << c3*c4<<endl;
    return 0;


}
