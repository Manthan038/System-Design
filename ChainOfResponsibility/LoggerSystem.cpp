
#include <bits/stdc++.h>
using namespace std;

class logger {
    protected:
    shared_ptr<logger> nextObj;
    
    public:
      void setNext(shared_ptr<logger> obj){
          nextObj = obj;
      }
      virtual void print_info(const string &level, const string &mssg) {
          if (nextObj){
              nextObj->print_info(level,mssg);
          }
      }
    
};

class info : public logger {
    public:
     
    void print_info(const string &level, const string &mssg) {
        if (level == "info"){
            cout<<"[INFO SECTION] : "<<mssg<<" \n";
        } else {
            logger::print_info(level, mssg);
        }
    }
};


class debug : public logger {
    public:
     
    void print_info(const string &level, const string &mssg) {
        if (level == "debug"){
            cout<<"[DEBUG SECTION] : "<<mssg<<" \n";
        } else {
            logger::print_info(level, mssg);
        }
    }
};

class error : public logger {
    public:
     
    void print_info(const string &level, const string &mssg) {
        if (level == "error"){
            cout<<"[ERROR SECTION] : "<<mssg<<" \n";
        } else {
            logger::print_info(level, mssg);
        }
    }
};


int main()
{
    
    auto info_log = make_shared<info>();
    auto debug_log = make_shared<debug>();
    auto error_log = make_shared<error>();
    
    
    debug_log->setNext(move(error_log));
    info_log->setNext(move(debug_log));
    
    info_log->print_info("info", "this message is for info");
    info_log->print_info("debug", "debug this code");
    info_log->print_info("error", "code contains errors ");
    
    cout<<"\n Done";
    return 0;
}
