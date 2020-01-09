#ifndef classPerson_hpp
#define classPerson_hpp

#include "classPersonIf.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <memory>
#include <iterator>
#include <algorithm>

class Person: public PersonIf
{
    private:
    std::string name;
    std::string surname;
    std::string address;
    int age;
    std::string pesel;
    std::string date_of_birth;
    int licznik;
    public:
    Person();
    Person( const std::string& _name, 
            const std::string& _surname,
            const std::string& _address, 
            const int& _age, 
            const std::string& _pesel,
            const std::string& _date_of_birth,
            int _licznik ); 
    const std::string &get_name() const{return name;}  
    const std::string &get_surname() const{return surname;} 
    const std::string &get_address() const{return address;}  
    const int get_age() const{return age;}
    const std::string get_pesel() const{return pesel;}  
    const std::string get_date_of_birth() const{return date_of_birth;}  
    const int get_licznik() const{return licznik;}

    friend std::ostream& operator<<(std::ostream& s,const Person & p);

    friend std::ostream& operator<<(std::ostream& r, std::pair<const std::string, std::shared_ptr<Person>> p);

    Person get_random_person();

    ~Person();  
};

#endif