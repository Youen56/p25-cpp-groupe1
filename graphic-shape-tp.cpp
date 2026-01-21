/* implement graphic shapes and an editor

the graphic shapes:
   - are Circle (radius), Rectangle (width, height) ...
   - have a position: x, y
   - can be moved
   - have member function that check if a shape is at a given position
     (juste check that the given point is inside the smallest rectangular bounding box englobing the shape)
   - have a member function that compute the area of the shape (fix a value for PI)

the editor:
  - contains a list of graphic shapes
  - can add/remove an existing graphic-shape to the list
  - has a member function find that returns the (first) graphic shape at a given position
  - can remove the graphic-shape found at a given position
  - can compute the area of the shape found at a given position

We can add a new shape to your code (Square) WITHOUT modifying your classes !
Only by adding some code and modifying the main function.

*/
#include <iostream>
#include <vector>
#include <stdexcept>

class Shape{
  int x;
  int y;
protected:
  Shape(int px, int py): x(px), y(py){
    if (px<0 or py<0){
      throw std::invalid_argument(std::string("we throw an exception of type: invalid argument: Shape cannot use a negative value for positionning"));
    }
  }

public:
virtual double area() =0;// Stupide mais obligatoire pour pouvoir accéder aux autres éléments
  void move(int dx, int dy){
    if (x+dx<0){
throw std::invalid_argument(std::string("we throw an exception of type: invalid argument: Shape cannot be moved outside the boundaries in x"));
    }
    if (y+dy<0){
      throw std::invalid_argument(std::string("we throw an exception of type: invalid argument: Shape cannot be moved outside the boundaries in y"));
    }
    x=x+dx;
    y=y+dy;
  }
};
class Circle : public Shape{
  int radius;
public:
  Circle (int xx, int yy, int r): Shape(xx,yy),radius(r){
    if (r<0){
      throw std::invalid_argument(std::string("we throw an exception of type: invalid argument: circle cannot have a negative radius"));
    }
  }
  double area(){
    return 3.14159*radius*radius;
  }
};

class Rectangle : public Shape{
  int wi;
  int he;
public:
  Rectangle(int xx, int yy, int w, int h): Shape(xx,yy),wi(w),he(h){
  }
  double area(){
    return wi*he;
  }
};


int main()
{
    Circle c1(100, 50, 12.4);
    //Circle* pc1= &c1; // c'est l'adresse de tout l'objet cercle
    //Circle& rc1= c1; // il fait tout seul un pointeur vers cet objet sans qu'on ait beoin de l'indiquer
    //Circle cc1=c1;//  il va juste en faire une copie. 
    c1.move(15, 67); // il va aller la chercher dans shape car il ne va pas la trouver dans circle. 
    std::cout<<c1.area()<<std::endl;

    Rectangle r1(100,300,56,67);
    r1.move(8,10);
    std::cout<<r1.area()<<std::endl;
    std::vector <Shape*> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&r1);

    for (int i=0; i< shapes.size(); i++){
      std::cout<<shapes[i]->area()<<std::endl;
    }

}