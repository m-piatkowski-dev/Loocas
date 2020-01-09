#ifndef struktury_hpp
#define struktury_hpp

#include "classPerson.hpp"
#include <string>
#include <memory>

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

#endif