/*

implement a hierarchy of classes for arithmetic expression manipulations:
    - the classes holds, evaluates and prints arithmetic expressions
    - print in infix, prefix or postfix notation

Additional work:
   - note that the postfix notation is also called Reverse Polish notation (RPN)
   - it is a mathematical notation in which operators follow their operands
   - this notation does not need any parentheses i.e. this notation is non ambigu
   - => you can read (easily) RPN expressions using a stacks
  implement a code to read RPN expression and store them with your class objects
  RPN arithmetic expression are passed as main command-line arguments

./main 87 12 - + 75 -
*/
#include <iostream>
class Expression {
public:
    virtual int eval() const = 0;   
    virtual void print() const = 0; 
    virtual ~Expression() = default; 
};

// 2. Constante
class Constant : public Expression {
private:
    int number;
public:
    Constant(int a) : number(a) {}

    int eval() const override {
        return number;
    }

    void print() const override {
        std::cout << number << " ";
    }
};

// 3. Moins Unaire
class UnaryMinus : public Expression {
private:
    const Expression& operand; 
public:
    UnaryMinus(const Expression& e) : operand(e) {}

    int eval() const override {
        return -operand.eval();
    }

    void print() const override {
        operand.print();
        std::cout << "- "; 
    }
};

// 4. Opérateurs Binaires

class Plus : public Expression {
private:
    const Expression& left;
    const Expression& right;
public:
    Plus(const Expression& l, const Expression& r) : left(l), right(r) {}

    int eval() const override {
        return left.eval() + right.eval();
    }

    void print() const override {
        left.print();
        right.print();
        std::cout << "+ ";
    }
};

class Minus : public Expression {
private:
    const Expression& left;
    const Expression& right;
public:
    Minus(const Expression& l, const Expression& r) : left(l), right(r) {}

    int eval() const override {
        return left.eval() - right.eval();
    }

    void print() const override {
        left.print();
        right.print();
        std::cout << "- ";
    }
};

class Divide : public Expression {
private:
    const Expression& left;
    const Expression& right;
public:
    Divide(const Expression& l, const Expression& r) : left(l), right(r) {}

    int eval() const override {
        int denom = right.eval();
        if (denom == 0) throw std::runtime_error("Erreur: Division par zero !");
        return left.eval() / denom;
    }

    void print() const override {
        left.print();
        right.print();
        std::cout << "/ ";
    }
};
int main()
{
    try
    {
        // Constant c1(12), c2(-87), c3(23); // try it (-87 is not an unsigned int)
        Constant c1(12), c2(87), c3(75);

        c1.print(); // affiche 12
        std::cout << std::endl;
        std::cout << "eval " << c1.eval() << std::endl; // affiche 12

        UnaryMinus u1(c1);
        u1.print(); // affiche 12 -
        std::cout << std::endl;
        std::cout << "eval " << u1.eval() << std::endl; // affiche -12

        Plus p1(c2, u1);
        p1.print(); // affiche 87 12 -+
        std::cout << std::endl;
        std::cout << "eval " << p1.eval() << std::endl; // affiche 75

        Minus m1(p1, c3);
        m1.print(); // 87 12 -+75 -
        std::cout << std::endl;
        std::cout << "eval " << m1.eval() << std::endl; // affiche 0

        Divide d1(p1, m1);
        std::cout << std::endl;
        std::cout << d1.eval() << std::endl; // throws an instance of 'std::runtime_error'

        /*std::vector<???> expr;
        expr.push_back(???c1);
        expr.push_back(???u1);
        // parcourez le vecteur
        */
    }
    catch (std::runtime_error &e)
    {
        // affiche zero divide error
        std::cout << e.what() << std::endl;
    }
    return 0;
}
