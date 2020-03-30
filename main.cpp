#include <iostream>
using namespace std;

class LinkedList {

    public:
        int value;
        LinkedList* next;
        
        LinkedList(int new_value, LinkedList* new_next){
            value = new_value;
            next = new_next;
        }
        LinkedList(signed int size){
            cout << "Standard constructor call" << endl;
            *this = LinkedList(0,NULL);
            if (size > 1){
                LinkedList *traverser = this;
                for (int i = 1; i < size; i++){
                    LinkedList *new_list = new LinkedList(i,NULL);
                    traverser->next = new_list;
                    traverser = new_list;
                }    
            }
        }
        void operator << (int new_value){
            LinkedList *append = new LinkedList(new_value, NULL);
            cout << "Operator << adding " << append->value << endl;
            this->getLastListItem().next = append;
        }

        void operator = (int new_value){
            this->value = new_value;
        }

        void print(){
            LinkedList *traverser = this;
            while (traverser->next != NULL){
                cout << traverser->value << " " << traverser->next << endl;
                traverser = traverser->next;
            } cout << traverser->value << " " << traverser->next << endl;
        }
    private:
        LinkedList& getLastListItem(){
            cout << "getLastListItem beign called" << endl;
            LinkedList *traverser = this;
            while (traverser->next != NULL) {
                traverser = traverser->next;
            } return *traverser;
        }
};

/**
 * Desafios de aprender c++:
 * - Fazer minha classe stackar operador de append (list << 5 << 7)
 **/
int main() {
    LinkedList list = LinkedList(25);
    list.print();
    list << 5;
    list.print();
}