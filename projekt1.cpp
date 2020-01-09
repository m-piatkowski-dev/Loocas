#include <functions.cpp>


int main()
{
    std::srand(time(nullptr));
    Person::Person s;
    
    for(unsigned int i=0; i<10; ++i)
    { 
        std::shared_ptr<Person> p=std::make_shared<Person>(s.get_random_person());
        baza.insert({p->get_pesel(),p});
    }
    print_container(baza);std::cout<<"######################################################\n"; 
    std::cout<<"Wyświetl posortowane po: \n0.PESEL\n1.NAME\n2.SURNAME\n3.ADDRESS\n4.AGE\n5.DOB: ";
    int type, start_position, amount;
    std::cin>>type;
    std::cin>>start_position;
    std::cin>>amount;
    get_data(type,start_position, amount);
   
    
    auto it=sort_name.begin();
    std::cout<<(*it).use_count()<<" <-ilość sptr "<<sizeof(*it)<<"<- rozmiar wskaźnika sptr "<<sizeof(s)<<"<- rozmiar obiektu klasy Person\n";

return 0;
}# Loocas function.cpp projekt.hpp
