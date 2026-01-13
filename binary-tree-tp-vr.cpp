#include <iostream>
// vr: mes corrections dans votre code

struct Node
{
     int value;
     Node *left;  // On met des pointeurs ici(avec l'*)
     Node *right; // votre code là
     /*
     Node(int a) : value(a)
     {
          left = nullptr;
          right = nullptr;
     } // faire un constructeur qui met left et right à Nullptr
     */

     // vr: préférez initialiser les attributs de l'objet que vous construisez
     //              directement dans la liste d'initialisation
     // parce que ce sont des initialisations pas des affectations
     Node(int a) : value(a), left(nullptr), right(nullptr)
     {
          //      left = nullptr; // vr: ce sont des affectations on veut des
          //      right = nullptr;
     } // faire un constructeur qui met left et right à Nullptr

     void insert(int a)
     {
          if (a<value){
               if (left==nullptr){
                    Node *n = new Node(a); 
                    left = n; 
               }
               else{
                    left->insert(a);
               }
          }
          else{
               if (right==nullptr){
                    Node *n = new Node(a); 
                    right = n; 
               }
               else{
                    right->insert(a);
               }
          }
     }
     bool search (int v) {
          if (value == v){
               return true;
          }
          if ((left!= nullptr) and (v<value)){
               return left->search(v);
          }
          if ((right!= nullptr) and (v>value)){
               return right->search(v);
          }
          else{.     
          return false; 
          }
     }
};

struct BinaryTree
{
     Node *root; // votre code là
     BinaryTree () : root(nullptr) {}

     // et ces fonctions à implémenter à minima
     void insert(int a)
     {
          if (root == nullptr)
          {               // NON
                          // vr: il faut ici allouer quelque part un nouvel objet de type Node...
                          //     la seule mémoire qui existera encore après la sortie de cette méthode insert
                          //     est le tas (heap) où on alloue les objets avec new et les désalloue avec delelte
                          //     (ou new [] et delete [])
                          // vous ne pouvez pas créer l'objet dans la stack (pile d'exécution) comme vous
                          // avez fait pour b
                         // NON
               Node *n = new Node(a); // OUI
               root = n;
          }
          else
          {
               // vr: on délègue l'insertion de l'élément au Node racine
               // puisqu; il existe
               root->insert(a);
          }
     }

     // traversée de l'arbre en profondeur
     void depth()
     {
     }
     bool search(int v) { 
          if (root->value==v){
               return true;
          }
          if ((root->left==nullptr)and(root->right==nullptr) ){
               return false;
          }
          if (v<root->value){
               return root->left->search(v);
          }
          if (v>root->value){
               return root->right->search(v);
          }
          return false; 
     }

     // celle là est plus difficile
     void print() {}
};

int main()
{
     BinaryTree b;
     b.insert(8);
     b.insert(4);
     b.insert(6);
     b.insert(12);
     b.insert(10);
     b.insert(11);
     b.insert(9);
     b.insert(2);
     b.insert(1);
     b.insert(3);
     b.insert(5);
     b.insert(14);
     b.insert(15);
     b.insert(13);
     b.insert(7);

     b.print();

     b.depth();

     std::cout << "Est-ce que 12 est dans l'arbre ?" << std::boolalpha << b.search(12) << std::endl;
     std::cout << "Est-ce que 99 est dans l'arbre ?" << std::boolalpha << b.search(99) << std::endl;
     return 0;
}
