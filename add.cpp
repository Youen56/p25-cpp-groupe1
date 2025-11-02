#include <iostream>
#include <string>

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    if (argc==1){
        std::cerr <<"Not enough arguments"<< std::endl;
        return -1;
    }
    int i = 1;
    int a =0;
    while (i < argc)
    {
        int b = std::stoi(argv[i]);
        a+=b;
        i = i + 1;
    }
    std::cout<<"le résultat est "<< a << std::endl;

}