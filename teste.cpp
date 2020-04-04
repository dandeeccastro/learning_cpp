#include <iostream>
#include <unistd.h>

using namespace std;

class Example {
    public: 
        int value;

        Example(int new_value) {
            value = new_value;
        } 

        Example* getPointerToExampleObject(){
            return this;
        }

        Example& getAdressToExampleObject(){
            return *this;
        }
};

int main(){
    cout << "Generating Example objects A and B" << endl;
    Example a = Example(3);
    Example b = Example(5);
    cout << "Printing result from pointer function of a and b" << endl;
    cout << a.getPointerToExampleObject()->value << " " << b.getPointerToExampleObject()->value << endl;
    cout << "Printing result from address function of a and b" << endl;
    cout << a.getAdressToExampleObject().value << " " << b.getAdressToExampleObject().value << endl;
    return 0;
}