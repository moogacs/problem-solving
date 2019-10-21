#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;

int main() {
    int a; long b; char c; float d; double e;
    cin>>a>>b>>c>>d>>e;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout.precision(3);
    cout<<fixed<<d<<endl;
    cout.precision(9);
    cout<<fixed<<e<<endl;
    return 0;
}
