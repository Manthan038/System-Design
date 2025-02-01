/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class custom_string {
    private:
    char* data;
    unsigned int len ;
    
    public:
    custom_string(): data(nullptr), len(0) {
        
    } /// just handling case when user intialize string object without
    // any string
    custom_string(const char *data) {
        len = strlen(data);
        this->data = new char[len + 1]; // just 1 more size to store '\0' end of online
        strcpy(this->data,data);
    }
    
    unsigned int getlength() const{
        return len;
    }
    
    // copy constructor
    custom_string(const custom_string &strobj){
        
        /// Donn't just deep copy like below
        // len = strobj.len;
        // data = strobj.data;  // deep copy // same object shared over all the pointer
        
        
        len = strobj.len;
        data = new char[len+1];
        strcpy(this->data, strobj.data);  //shallow copy
        
    }
    
    /// assingment operator overload
    
    custom_string& operator=(const custom_string &st){
        if(data){
            delete[] data;
            len = 0;
        }
        
        data = st.data;
        len = st.len;
        
        // below is alternate way to do this
        // as if suppose , you have deleted the curretn resource 
        /// but due to some reason , it's not successfully copied the resource to current 
        // then you will lose all the data or you just need to create a new temp which will
        // store before deleting and have to manage that
        /// to avoide that headache , you can use below mentioned steps
        
        /***
         * custom_string& operator=(custom_string st). << this will call copy constructor
         * {
         *   swap(*this, st);
         *   /// now define swap function , and to swap of resource 
             
         *}
         * **/
         
        
        return *this;
        
    }
    
    friend ostream& operator<<(ostream& ot, const custom_string &st);
    
    
};

ostream& operator<<(ostream& ot, const custom_string &st) {
    ot<<st.data;
    return ot;
}


int main()
{
    custom_string str1("manthan");
    
    
    cout<<str1<<"\n";
    custom_string str2(str1) ;
    
    str2 = "mayank";
    cout<<"this is str2 "<<str2 << " and str1 is "<<str1;
    
    

    return 0;
}