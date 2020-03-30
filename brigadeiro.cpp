#include <iostream>
#include <unistd.h>

int main(){
    std::cout << "Fazendo deliciosos brigadeiros" << std::endl;
    for (int i = 10; i > 0; i--){
        sleep(1);
        std::cout << i << std::endl;
    } std::cout << "Pronto! Agora só pegar na geladeira!" << std::endl;
    return 0;
}