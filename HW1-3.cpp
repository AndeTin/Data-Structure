#include<iostream>
#include<string>

using namespace std;

string name;
int x,y;

cout << "Please input how many arrays and how many characters in each array:" << endl;
cin >> x >> y;
string** arr = new string* [x];
for(int i=0;i<x;i++){
    arr[i] = new string[y+1];
}