/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class TV {
    private:
     bool on;
     public:
       TV(): on(false) {
          showTV(); 
       }
       
       void startTV(){
           on = true;
       }
       
       void offTV(){
           on = false;
       }
       
       void showTV(){
           cout<<"Now TV is "<<(on?"open":"close")<<"\n";
       }
};

class command {
    public:
    virtual void execute() = 0;
    
};

class StartScreen : public command {
    TV *tv;
    
    public:
       StartScreen(TV &obj){
         tv = &obj;
       } 
       
     void execute() {
         tv->startTV();
         tv->showTV();
     }  
       
};

class offScreen : public command {
    TV *tv;
    
    public:
       offScreen(TV &obj){
         tv = &obj;
       } 
       
     void execute() {
         tv->offTV();
         tv->showTV();
     }  
       
};


class remote {
    command *redButton;
    command *GreenButton;
    public:
       remote(){
           
       }
     
     void setRedButton(command *obj){
         redButton = obj;
     }
     
     void clickRedButton(){
         redButton->execute();
     }
     
     void setGreenButton(command *obj){
         GreenButton = obj;
     }
     
     void clickGreenbutton(){
         GreenButton->execute();
     }
       
};






int main()
{
    
    
    
    TV t;
    remote r;
    
    ///green button for closing the tv 
    // red button for openning tv
    r.setRedButton(new StartScreen(t));
    r.setGreenButton(new offScreen(t));
    
    /// click any buttoin
    
    r.clickRedButton();
    
    //close the tv
    r.clickGreenbutton();
    
    
    
}