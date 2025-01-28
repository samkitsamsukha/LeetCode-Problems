#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    int copy = x;
    int d;
    long s=0;
    while(x>0){
        d = x%10;
        s = s*10 + d;
        x = x/10;
    }
    if(s == copy){
        return true;
    }
    else return false;
}

int main(){
    int n;
    cin >> n;
    cout << boolalpha;
    cout << isPalindrome(n) << endl;
}