#include <iostream>
#include <map>


using namespace std;

union MyUnion 
{
    int intValue;
    float floatValue;
    char charValue;
};

int main() {

    MyUnion myUnion;

    myUnion.intValue = 50;
    cout << "intValue: " << myUnion.intValue << endl;
    myUnion.floatValue = 4.3;
    cout << "intValue: " << myUnion.floatValue<< endl;
    myUnion.charValue = 'A';
    cout << "intValue: " << myUnion.charValue << endl;



    return 0;
}