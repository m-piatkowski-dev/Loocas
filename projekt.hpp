#ifndef projekt_hpp
#define projekt_hpp
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <memory>
#include <iterator>
#include <algorithm>

std::map<std::string, std::shared_ptr<Person>> baza;
    
std::multiset<std::shared_ptr<Person>, Comp_name > sort_name;
std::multiset<std::shared_ptr<Person>, Comp_surname> sort_surname;
std::multiset<std::shared_ptr<Person>, Comp_address> sort_address;
std::multiset<std::shared_ptr<Person>, Comp_age> sort_age;
std::multiset<std::shared_ptr<Person>, Comp_dob> sort_dob;
std::multiset<std::shared_ptr<Person>, Comp_licznik> sort_licznik;

class PersonIf 
{
   public:
       virtual const std::string & get_name() const = 0;
       virtual const std::string & get_surname() const = 0;
       virtual const std::string & get_address() const = 0;
       virtual const int get_age() const = 0;
       virtual const std::string get_date_of_birth() const = 0;// zwróci string w formacie "YYYY.MM.DD" 
       virtual const std::string get_pesel() const = 0;
       virtual ~PersonIf()=default;
};

class Person: public PersonIf
{
    public:
    Person();
    Person( const std::string& _name, 
            const std::string& _surname,
            const std::string& _address, 
            const int& _age, 
            const std::string& _pesel,
            const std::string& _date_of_birth,
             int _licznik); 
    
    const std::string & get_name();
    const std::string & get_surname();
    const std::string & get_address();  
    const int get_age(); 
    const std::string get_date_of_birth();  
    const std::string get_pesel();  
    const int get_licznik();

    friend std::ostream& operator<<(std::ostream& s,const Person & p);
    friend std::ostream& operator<<(std::ostream& r, std::pair<const std::string, std::shared_ptr<Person>> p);

    ~Person();

    private:
    std::string name;
    std::string surname;
    std::string address;
    int age;
    std::string pesel;
    std::string date_of_birth;
    int licznik=1;
};

Person get_random_person();
struct Comp_name
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_name() < p2->get_name()) ;
    }
};

struct Comp_surname
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_surname() < p2->get_surname()) ;
    }
};
struct Comp_address
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_address() < p2->get_address()) ;
    }
};
struct Comp_age
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_age() < p2->get_age()) ;
    }
};
struct Comp_dob
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_date_of_birth() < p2->get_date_of_birth()) ;
    }
};
struct Comp_licznik
{
    bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2)const
    {    
        return (p1->get_licznik() < p2->get_licznik()) ;
    }
};

template <class T>
void print_container(const T& container);

void get_data(const int type, const int start_position, const int amount);



#endif