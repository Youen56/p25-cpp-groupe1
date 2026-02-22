#include <iostream>
#include <vector>
#include <stdexcept>
struct Edge{
    double value;
    int begin;
    int end;
    Edge(int a, int b, double c):value(c),begin(a),end(b){
        
    }
    void print(){
        std::cout<<begin<<"- ("<<value<<")->"<<end<<std::endl;
    }

};

struct Vertex{
    int name;
    std::vector<Edge*> v;
    Vertex(int i):name(i){

    }
    void print(){
        for (int i=0;i<=v.size();i++){
            std::cout<<"Vertex"<<i<<std::endl;
            print v[i];
        }
    }
    void add(Edge a){
        //v.push_back(a);

    }
    
};

struct Graph{ 
    std::vector<Vertex*> v;
    void addEdge(int a, int b, double c){
        if (a> v.size() or b>v.size()){
            int min;
            int max;
            if (a>b){
                max=a;
                if (b>v.size()){
                    min=v.size()
                };
                else{
                    min=b;
                };
            }
            else{
                max=b;
                if (a>v.size()){
                    min=v.size()
                };
                else{
                    min=a;
                };
            }
            for (int i=min;i<=max;i++){
                v.push_back(new Vertex(i));
            }
            }
        v[a].add(Edge(int a, int b, double c));
        };
    void print(){
        for (int i=0;i<=v.size();i++){
            std::cout<<"Du noeud"<<i<<std::endl;
            v[i].print();
        }
    }

};





int main(){
    Graph g;

    g.addEdge(2,5,17.9);
    g.addEdge(5,3,23.9);
    g.addEdge(3,4,16.9);
    g.addEdge(4,0,699.9);
    g.print();
}