#include<iostream>
#include<string>
#include<vector>
using namespace std;

class String{
    private:
        vector<char> I;
    public:
        String (string i){
            for(int j = 0 ; j < (int)i.size() ; j++){
                I.push_back(i[j]);
            }
        }

        void Frequency(String in){
            vector<char> r;
            int count = 0;
            r.push_back(in.I[0]);
            for(int i = 1 ; i < (int)in.I.size() ; i++){
                for(int j = 0 ; j < (int)r.size() ; j++){
                    if(in.I[i] == r[j]){
                        break;
                    }
                    if(j == (int)r.size() - 1){
                        r.push_back(in.I[i]);
                    }
                }
                
            }
            for(int i = 0 ; i < (int)r.size() ; i++){
                for(int j = 0 ; j < (int)in.I.size() ; j++){
                    if(r[i] == in.I[j]){
                        count++;
                    }
                }
                cout << r[i] << " : " << count << endl;
                count = 0;
            }
        }
};

int main(){
    string i;
    cout << "Please enter a string: ";
    getline(cin,i);
    String F(i);
    F.Frequency(F);
    return 0;
}

