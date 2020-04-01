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
        LinkedList& push(int new_value){
            LinkedList *append = new LinkedList(new_value,NULL);
            this->get_last_list_item().next = append;
            return *this;
        }
        LinkedList& pop(){
            LinkedList *second = &this->get_second_to_last_item();
            LinkedList *last = &this->get_last_list_item();
            second->next = NULL;
            last->next = NULL;
            return *last;
        }
        // Still not functional
        LinkedList& pop(int index){
            LinkedList* before = &this[index - 1];
            LinkedList* target = &this[index];
            cout << "POP PRINT START" << endl;
            cout << before->value << " " << target->value << endl;
            cout << "POP PRINT END" << endl;
            return *target;
        }
        LinkedList& operator << (int new_value){
            return this->push(new_value);
        }
        LinkedList& operator [] (int index) {
            LinkedList *traverser = this;
            while (index > 0){
                traverser = traverser->next;
                index--;
            } return *traverser;
        }
        void print(){
            LinkedList *traverser = this;
            while (traverser->next != NULL){
                cout << traverser->value << " " << traverser->next << endl;
                traverser = traverser->next;
            } cout << traverser->value << " " << traverser->next << endl;
        }
    private:
        LinkedList& get_last_list_item(){
            // cout << "get_last_list_item beign called" << endl;
            LinkedList *traverser = this;
            while (traverser->next != NULL) {
                traverser = traverser->next;
            } return *traverser;
        }
        LinkedList& get_second_to_last_item(){
            LinkedList *traverser = this;
            while (traverser->next->next != NULL){
                traverser = traverser->next;
            } return *traverser;
        }
};

/**
 * Desafios de aprender c++:
 * 
 * - Fazer mais estruturas de dados
 * 
 **/
int main() {
    LinkedList list = LinkedList(25);
    list << 5 << 9;
    cout << list[10].value << endl;
    list.print();
    cout << list.pop(18).value << endl;
    list.print();
    return 0;
}