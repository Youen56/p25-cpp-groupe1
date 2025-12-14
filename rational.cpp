struct IntStack{
    int size;
    int nb=0;
    int* tab;//on fait ici directement un tableau de 12 cases, mais c'est globalement assez basique. 
    IntStack(int s):size(s), nb(0){//on peut déplacer le size pour faire un test sur la valeur si elle est négative et throw un truc.
        tab=new int[size];//allocation
    }
    ~IntStack(){
        delete [] tab;
    }
    bool is_full(){
        return nb>=size;
    }
    void push(int a){
        if (not is_full()){
            throw 0;
            tab[nb]=a;
            nb=nb+1;
        }
    }
};



#include<iostream>
struct Rational{
int num = 0;
int denom = 1;
Rational(int n, int d):num(n),denom(d)// redondant avec ce qui suit, c'est le même principe, il faut juste ajouter un const devant. 
{ // on n'a donc pas besoin de la suite si on a déja le début. 
    //num=n;
    //denom=d;// ici, c'est que int et denom ont déja une valeur avant, elles ont été initiallisées

}
void print(){
std::cout<<num<<"/"<<denom<<std::endl;
}
};// ne surtout pas oublier le point virgule ici car sinon il croit qu'on est ecore dans la classe...
void print(Rational* r){
std::cout<<(*r).num<<"/"<<(*r).denom<<std::endl;//soit r->num soit (*r)
}

void print2(Rational& r){//si on met un &, on ne recopie pas l'objet (mieux niveau place)
std::cout<<r.num<<"/"<<r.denom<<std::endl;
}


int main(){
    //Rational r(1, 2);
    //r.print();
    //print(&r);
    //return 0;
    {
        IntStack st(5);
        IntStack* ps= new IntStack(5);
    }// il donne de base le destructeur.
    return 0;
    IntStack st(15);
    st.push(-17);

    IntStack *ps= new IntStack(20000);
    ps->push(-17);
    delete ps;

    return 0;
}