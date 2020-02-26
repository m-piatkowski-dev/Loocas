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
    std::srand(time(nullptr));
    std::map<std::string, std::shared_ptr<Person>> baza;
    
    Person s;
try{
    if((argc<3)||((argc-2)%3!=0))
    {
        std::cout<<"Za malo parametrow 1 + 3*N ( powinno być: "
                 <<"$ ./projekt <ilosc osob do wygenerowania> <tryb sortowania 0-5>"
                 <<"<pozycja od ktorej wypisywac> <ile pozycji wypisac> )\n";
    }
    else if(argc > 32)
    {
        std::cout<<"Za duzo parametrow!(max 31 + nazwa programu!)\n";
    }
    else if(std::stoi(argv[1])<1 || std::stoi(argv[1])>1000000)
    {
        std::cout<<"1 parametr poza zakresem <1 - 1.000.000>\n";
    }
    else
    {
        for( int i=0; i<std::stoi(argv[1]); ++i)
        { 
            std::shared_ptr<Person> p = std::make_shared<Person>(s.get_random_person());
            baza.insert({p->get_pesel(),p});
        }
        
        for (int i=0; i<argc-2; i+=3 )
        {
            if( std::stoi(argv[i+2])<0 || std::stoi(argv[i+2])>6 )
            {
                std::cout<<"Nieprawidlowy zakres type sortowania!(2 parametr) <0-6> ! \n";
            }
            else if ( std::stoi(argv[i+3])<1 || std::stoi(argv[i+3])>std::stoi(argv[1]) )
            {
                std::cout<<"Nieprawidlowy zakres start_position wyswietlania!(3 parametr) <od <1> do <wartosc 1 parametru>> ! \n";
            }
            else if
            (
                (    
                  ( std::stoi(argv[1])   ==  std::stoi(argv[i+3]) ) && ( std::stoi(argv[i+4]) != 1  )  
                )
                ||
                ( 
                    std::stoi(argv[i+4])  >  std::stoi(argv[1])
                )
                ||
                ( 
                    std::stoi(argv[i+4])  <  0 
                )
                ||
                (
                   ( std::stoi(argv[i+4])  >  ( std::stoi(argv[1]) - std::stoi(argv[i+3]) ) +1) && ( std::stoi(argv[i+4]) != 1  ) 
                ) 
            ) 
            {
                std::cout<< "Nieprawidlowy zakres amount wyswietlania!(4 parametr) < zwykle przyjmuje zakes od <1> do <wartosc parametru 1>"
                         << "ale jest zależne od logiki <3 parametru>> ! \n";
            }
            else
            {
                get_data( baza, std::stoi(argv[i+2]), std::stoi(argv[i+3]), std::stoi(argv[i+4]) );
            }
        }
    }  
} catch (const std::exception& e) { 
    std::cout<< "Jako parametr wprowadzono litere zamiast cyfry!!"
                                           << "Blad wyrzucila funkcja: " << e.what()<<"\n";
} catch (...) { 
    std::cout<< "Wyskoczyl inny wyjatek ...\n"; 
}  

return 0;   
}
