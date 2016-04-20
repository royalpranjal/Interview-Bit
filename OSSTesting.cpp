#include<iostream>
#include<sstream>

using namespace std;

int main(){
    int i;
    ostringstream oss;
    string str = "";

    for(i = 0; i < 5; i++){
        oss << i;
        str = str + oss.str();
        oss.str("");
    }

    cout << str;

    return 0;
}
