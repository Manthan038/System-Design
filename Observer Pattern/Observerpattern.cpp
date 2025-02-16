/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class event {

    const string cls_name;
    const string info;
      public:
       event(const string &cls, const string &details): cls_name(cls), info(details){
           
       }
       
       void getinfo() const{
           cout<<"For Object class "<<cls_name<<" Info is :"<<info<<"\n";
       }
};

class Observer {
    public:
    void update(const event &obj) const {
        cout<<"this is class and have messge ";
        obj.getinfo();
        cout<<"\n";
    }
    
};

class  subject {
    std::vector<const Observer*> observer ;
    
    public:
    void addObservable(const Observer *obj){
        observer.push_back(obj);
    }
    
    virtual void getNotification(const event& et){
        cout<<"This is Subject \n";
        for ( auto obj : observer ){
            obj->update(et);
        }
    }
};


class wStation : public subject {
    
    public:
    void getNotification(const event& evt) override{
        cout<<"This is wheither station call \n";
        subject::getNotification(evt);
    }
    
};


int main(){
    subject *season = new wStation();
    
    Observer *custmer = new Observer();
    season->addObservable(custmer);
    
    
     Observer *custmer2 = new Observer();
    season->addObservable(custmer2);
    season->getNotification(event("first class","This is wstations info"));
    
}


