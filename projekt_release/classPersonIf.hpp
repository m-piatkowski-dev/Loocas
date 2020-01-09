#ifndef classPersonIf_hpp
#define classPersonIf_hpp

#include <string>

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

#endif