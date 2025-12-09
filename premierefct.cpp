#include <iostream>

void push(int* tab, int size, int nb, int a){
    if (nb>=size){
        std::cerr<<"End of the line, impossible to execute"<<std::endl;
    }
    tab[nb]=a;
    nb+=1;
}
void pop(int* tab, int size, int nb){
    int exte=tab[nb];
    std::cout<<exte<<std::endl;
    tab[nb];
}

int main(){
    int size=5;
    int tab[size];
    int nb=0;
    push(tab,size,nb,-27);//fonction à faire pour empiler le suivant
    push(tab,size,nb,-27);
    int e=pop(tab, size, nb); //doit renvoyer 90
}