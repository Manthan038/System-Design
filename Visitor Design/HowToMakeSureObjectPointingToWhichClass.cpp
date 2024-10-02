#include <bits/stdc++.h>
using namespace std;

class Derived1;
class Derived2;

class visitor {
    public:
    virtual void visit(Derived1 &) = 0;
    virtual void visit(Derived2 &) = 0;
};

class visitor_data : public visitor {
    string className;
    public:
    void visit(Derived1 &obj) {
        className =  "Derived1";
    }
    void visit(Derived2 &obj) {
        className = "Derived2";
    }
    
    string getName() const {
        return className;
    }
};

class Base {
    public:
     virtual void accept(visitor &) = 0;
};
class Derived1 : public Base {
    public:
      void accept(visitor &obj){
          obj.visit(*this);
      }
};

class Derived2 : public Base {
    public:
      void accept(visitor &obj){
          obj.visit(*this);
      }
};


int main() {
    Base *obj = new Derived1();
    visitor_data visit;
    obj->accept(visit);  /// suppoese this function does not show the class name;
    cout<<(visit.getName()) <<"\n";  // print Derived1
    
    
    Base *obj2 = new Derived2();
    
    obj2->accept(visit);
    
    cout<<(visit.getName())<<"\n";
    
    /// Interating way to achieve the same think but we have check for all object (in case of multiple)
    if (dynamic_cast<Derived2*>(obj2)){. /// Only true when it'll cast correctectly 
        cout<<"Derived 2 data \n";    
    }
    
    
    //3rd way to do
    //In base class write down a get class name virtual functin so that each time if pointer call then it'l print the 
    // class name 
    
    
}
