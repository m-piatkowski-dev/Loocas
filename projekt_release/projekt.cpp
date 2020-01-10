#include "function.hpp"
#include "classPerson.hpp"
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <memory>
#include <iterator>
#include <algorithm>
   
int main(int argc, char* argv[])
{
    std::map<std::string, std::shared_ptr<Person>> baza;
    std::srand(time(nullptr));
    Person s;
    
    for( int i=0; i<std::stoi(argv[1]); ++i)
    { 
        std::shared_ptr<Person> p=std::make_shared<Person>(s.get_random_person());
        baza.insert({p->get_pesel(),p});
    }
    print_container(baza);
    std::cout<<"WZORZEC /|\\ \n######################################################\n"; 

    for (int i=0; i<argc-2; i+=3 )
    {
        get_data(baza,std::stoi(argv[i+2]),std::stoi(argv[i+3]),std::stoi(argv[i+4]));
    }    
return 0;
}
