#include "projekt_r.hpp"
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

int main()
{
    std::map<std::string, std::shared_ptr<Person>> baza;
    std::srand(time(nullptr));
    Person s;
    
    for(unsigned int i=0; i<10; ++i)
    { 
        std::shared_ptr<Person> p=std::make_shared<Person>(s.get_random_person());
        baza.emplace(std::pair<std::string, std::shared_ptr<Person>> (p->get_pesel(),p));
    }
    //print_container(baza);
    std::cout<<"######################################################\n"; 
    std::cout<<"Wyświetl posortowane po: \n0.PESEL\n1.NAME\n2.SURNAME\n3.ADDRESS\n4.AGE\n5.DOB: ";
    int type, start_position, amount;
    std::cin>>type;
    std::cin>>start_position;
    std::cin>>amount;
    get_data(baza, type, start_position, amount);
   
    
    //auto it=sort_name.begin();
   //ls std::cout<<(*it).use_count()<<" <-ilość sptr "<<sizeof(*it)<<"<- rozmiar wskaźnika sptr "<<sizeof(s)<<"<- rozmiar obiektu klasy Person\n";

return 0;
}
