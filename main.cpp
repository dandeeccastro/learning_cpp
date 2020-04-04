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
        LinkedList pop(){
            LinkedList *second = &this->get_second_to_last_item();
            LinkedList *last = &this->get_last_list_item();
            second->next = NULL;
            last->next = NULL;
            LinkedList value = *last;
            delete last;
            return value;
        }
        LinkedList& operator [] (int index) {
            return this->get_item_by_index(index);
        }
        LinkedList pop(int index){
            LinkedList* before = &this->get_item_by_index(index - 1);
            LinkedList* target = before->next;
            before->next = target->next;
            target->next = NULL;
            LinkedList value = *target;
            delete target;
            return value;
        }
        LinkedList& operator << (int new_value){
            return this->push(new_value);
        }
        LinkedList& search (int value) {
            LinkedList* traverser = this;
            while (traverser->value != value && traverser->next != NULL) {
                traverser = traverser->next;
            } if (traverser->value != value) traverser = NULL;
            return *traverser;
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
        LinkedList& get_item_by_index(int index) {
            LinkedList *traverser = this;
            while (index > 0) {
                traverser = traverser->next;
                index--;
            } return *traverser;
        }
};

/**
 * Desafios de aprender c++:
 * 
 * - Fazer mais estruturas de dados
 * - Criar método privado para pegar item baseado no indice
 * - 
 **/
int main() {
    LinkedList list = LinkedList(25);
    list << 5 << 9;
    cout << list[10].value << endl;
    cout << list.pop(4).value << endl;
    LinkedList item = list.search(10);
    cout << item.value << endl;
    return 0;
}