#include <iostream>
#include <stdexcept> // Nécessaire pour std::length_error
#include <string>

// --- Fonctions utilitaires ---


class Stack{
    friend std::ostream &operator<<(std::odtream &os, const Stack &st);
    
    private:
        int* pile;
        int size;
        int nb;
    public:
    Stack(int a): size(a),nb(0){
        pile= new int[size];
    }
    ~Stack(){
        delete[] pile;
    }
    Stack(const Stack& other) : size(other.size), nb(other.nb) {
        // On alloue un NOUVEAU tableau indépendant
        pile = new int[size];
        
        // On copie les valeurs une par une
        for (int i = 0; i < nb; ++i) {
            pile[i] = other.pile[i];
    }
}
    Stack& operator=(const Stack& other) {
        if (this == &other) {
            return *this; 
        }
        delete[] pile;
        size = other.size;
        nb = other.nb;
        pile = new int[size];
        for (int i = 0; i < nb; ++i) {
            pile[i] = other.pile[i];
        }
        return *this;
    }
    void print(int *argv, int size, int nb) {
    std::cout << "Pile (taille " << nb << "/" << size << ") : [ ";
    for (int i = 0; i < nb; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << "[" << std::endl;
}

// Renvoie true si la pile est vide
bool is_empty() {
    return (nb == 0);
}

// Renvoie true si la pile est pleine
bool is_full() {
    return (nb == size);
}

// --- Fonctions principales ---

// Ajoute un entier. 
// Note : nb est passé par référence (&nb) pour être modifié.
void push(int a) {
    
    if (is_full()) {
        throw std::length_error("Erreur push: La pile est pleine !");
    }
    
    // Si tout va bien
    pile[nb] = a;
    nb += 1;
}

// Retourne l'élément du haut sans dépiler
int top() {
    if (is_empty()) {
        throw std::length_error("Erreur top: La pile est vide !");
    }
    
    return pile[nb - 1];
}

// Retourne l'élément du haut et dépile
int pop() {
    
    if (is_empty()) {
        throw std::length_error("Erreur pop: La pile est vide !");
    }

    nb -= 1;
    return pile[nb];
}
};

void print(int *argv, int size, int nb) {
    std::cout << "Pile (taille " << nb << "/" << size << ") : [ ";
    for (int i = 0; i < nb; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << "[" << std::endl;
}

// Renvoie true si la pile est vide
bool is_empty(int *argv, int size, int nb) {
    return (nb == 0);
}

// Renvoie true si la pile est pleine
bool is_full(int *argv, int size, int nb) {
    return (nb == size);
}

// --- Fonctions principales ---

// Ajoute un entier. 
// Note : nb est passé par référence (&nb) pour être modifié.
void push(int *argv, int size, int &nb, int a) {
    // Vérification : Pointeur nul (si la stack est mal créée)
    if (argv == nullptr) {
        throw std::invalid_argument("Erreur: La pile n'est pas allouée (pointeur null).");
    }

    // Vérification : Pile pleine
    if (is_full(argv, size, nb)) {
        throw std::length_error("Erreur push: La pile est pleine !");
    }
    
    // Si tout va bien
    argv[nb] = a;
    nb += 1;
}

// Retourne l'élément du haut sans dépiler
int top(int *argv, int size, int nb) {
    if (argv == nullptr) throw std::invalid_argument("Erreur: Pointeur null.");
    
    if (is_empty(argv, size, nb)) {
        throw std::length_error("Erreur top: La pile est vide !");
    }
    
    return argv[nb - 1];
}

// Retourne l'élément du haut et dépile
// Note : nb est passé par référence (&nb)
int pop(int *argv, int size, int &nb) {
    if (argv == nullptr) throw std::invalid_argument("Erreur: Pointeur null.");

    if (is_empty(argv, size, nb)) {
        throw std::length_error("Erreur pop: La pile est vide !");
    }

    nb -= 1;
    return argv[nb];
}

// --- Gestion Mémoire ---

int* create(int size) {
    // Allocation dynamique dans le tas (Heap)
    int* t = new int[size]; 
    return t;
}

void delete_stack(int *argv) {
    delete[] argv;
}

// --- Main ---

int main() {
    int size = 5;
    int nb = 0;
    
    // Création propre avec new via la fonction create
    int* mon_tableau = create(size); 

    try {
        std::cout << "--- Test 1: Remplissage ---" << std::endl;
        push(mon_tableau, size, nb, 10);
        push(mon_tableau, size, nb, 20);
        push(mon_tableau, size, nb, 30);
        print(mon_tableau, size, nb);

        std::cout << "\n--- Test 2: Top et Pop ---" << std::endl;
        std::cout << "Top element: " << top(mon_tableau, size, nb) << std::endl; // Affiche 30
        
        int element_enleve = pop(mon_tableau, size, nb); // Enlève 30
        std::cout << "Element pop: " << element_enleve << std::endl;
        print(mon_tableau, size, nb); // Reste 10, 20

        std::cout << "\n--- Test 3: Provoquer une erreur (Pile Pleine) ---" << std::endl;
        push(mon_tableau, size, nb, 30);
        push(mon_tableau, size, nb, 40);
        push(mon_tableau, size, nb, 50); // Pile est pleine ici (5 éléments)
        print(mon_tableau, size, nb);
        
        // Cette ligne va déclencher l'exception car la taille max est 5
        std::cout << "Tentative d'ajout du 6eme element..." << std::endl;
        push(mon_tableau, size, nb, 60); 
    }
    catch (const std::exception& e) {
        // Affiche le message d'erreur spécifique défini dans le throw
        std::cerr << "EXCEPTION ATTRAPEE : " << e.what() << std::endl;
    }

    // Libération de la mémoire
    delete_stack(mon_tableau);

    return 0;
}