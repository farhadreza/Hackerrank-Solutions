#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student{
    private:
        string first_name;
        string last_name;
        int age;
        int standard;
        
    public:
        void set_first_name(string first_name)
        {
            while(first_name.length()>50){
                printf("invalid input.");
                cin>>first_name;
            }
         //   first_name=std::tolower(first_name);
            this->first_name=first_name;
            
        }
        
        string get_first_name()
        {
            return first_name;
            
        }
        
        void set_last_name(string last_name)
        {
            while(last_name.length()>50)
            {
                printf("invalid input.");
                cin>>last_name;
            }
            //last_name=std::tolower(last_name);
            this->last_name=last_name;
            
        }
        
        string get_last_name()
        {
            return last_name;
            
        }
        
        void set_age(int age)
        {
            this->age=age;
            
        }
        
        int get_age()
        {
            return age;
            
        }
        
        void set_standard(int standard)
        {
            this->standard=standard;
            
        }
        
        int get_standard()
        {
            return standard;
            
        }
        
        string to_string()
        {
            stringstream ss;
            char ch=',';
            ss<<get_age()<<ch<<get_first_name()<<ch<<get_last_name()<<ch<<get_standard();
            return ss.str();       
        }
        
       
        
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
