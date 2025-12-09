
int N;//sa valeur va donc etre 0
int main()
{
    int i = N;
    if (i < 3)
    {
        int i=17;//en rentrant dans le bloc, je peux omettre les acoolades. le i peut rester, car c'est la seule variable de ce bloc. ce nouveau i va le cacher
    }
    i=i+1;//en sortant, le i n'existe que dans son bloc, celui d'avant egal à 12 n'est plus caché.
}
// on va avoir le programme dans un bloc, et à part le N où on sait que c'est un int, en variable globale.
// en exécutant, il nous donne le programme, les variables muettes, et une pile d'exécution. il va commencer par créer un entier i qui vaut n en bas. il remmet une nouvelle brique ave i=17, puis à la sortie du bloc il retourne sur le i=0.
//


//pointers