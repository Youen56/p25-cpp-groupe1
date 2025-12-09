#include <iostream>

int add(int a, int b)
{
    return a + b;
}
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void swap2(int &a, int &b) {
    int aux=a;
    a=b;
    b=aux;
}
int main()
{

    int* pf = nullptr; //initialisation du pointeur à 0
    int i = 12;
    int j = 17;
    int *pi = &i;
    *pi = *pi * 10;
    int &ri = i; // on définit des références qui font que la case reste au même endroit, pas de variation on fait ici la même chose que au dessus
    ri = ri * 100;
    swap(&i, &j);
    swap2(i,j);//ca va directement marcher.
    std::cout << std::boolalpha << ((i == 17) and (j == 12)) << std::endl;
    // int k = add(i, j);

    // std::cout << k << std::endl;
    //  il met d'abord le i, puis le j dans la pile. ensuite il crée la brique k. ensuite, add met dans la pile a et b deux nouvelles briques, dans lesquelles il met les valeus.
    //  il renvoit 29, il redescend sans nettoyer.

    // int i = 12;                    // je demande un espace dans la mémoire, qui sera donc un int. on lui attribue la valeur 12
    // int *pi = &i;                  // adresse d'un int: int* il va donc mettre l'adresse de la zone où on peut trouver i
    // std::cout << *pi << std::endl; // il va à l'adresse qui lui est donné, dans la case pointé et il fait ses blabla
    //*pi = 15;                      // on peut donc change rla valeur de ce qu'il y a dans la case.
    // int j = i * 100;

    // int tab[2]; // j'ai ici un tableau de 2 int, 2 cases cote à cote de int
    // tab[0] = 12;
    // tab[1] = 56; // il vient vraiment marquer dans ces cases là, pas par dessus la pile.
    // int *ptab = tab;
    // std::cout << tab << std::endl; // on affiche ici le tableau de valeurs, si on fait ptab on a l'adresse du bloc
    //*tab va donc afficher la première case du tableau, l'adresse du suivant est tab+1

    // i = 17;

    // std::cout << &i << std::endl; // &i donne l'adresse de la case mémoire de i (ne foctionne pas avec 12 par exemple)

    // return 0;
}

// i est à la fois la valeur d'une case mémoire et la valeur. si on met un i=17,