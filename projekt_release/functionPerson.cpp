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

Person::Person() = default;

Person::Person( const std::string& _name, 
            const std::string& _surname,
            const std::string& _address, 
            const int& _age, 
            const std::string& _pesel,
            const std::string& _date_of_birth,
             int _licznik):
                name(_name), surname(_surname), address(_address),
                 age(_age), pesel(_pesel), date_of_birth(_date_of_birth), licznik(_licznik){}  

                 std::ostream& operator<<(std::ostream& s,const Person & p)
    {
        s <<std::setw(10)<<std::left<<p.get_name()<<" "<<std::setw(18)<<std::left<<p.get_surname()<<" "<<std::setw(20)<<std::left<<p.get_address()<<" "
          <<std::setw(4)<<std::left<<p.get_age()<<" "<<std::setw(15)<<std::left<<p.get_pesel()<<std::setw(15)<<std::left<<p.get_date_of_birth()
          <<std::setw(12)<<std::left<<"licznik: "<<std::left<<p.get_licznik()<<"."<<std::endl;
        return s;
    }
    std::ostream& operator<<(std::ostream& r, std::pair<const std::string, std::shared_ptr<Person>> p)
    {
        r <<"Pesel->"<<p.first<<" "<<*p.second<<std::endl;
        return r;
    }
Person Person::get_random_person()
    {
        const std::array<std::string, 10> imiona{"Anna", "Mariola", "Stefan", "Barbara", "Michal",
                                                 "Wojciech", "Pawel", "Karol","Roman","Ignacy"};
        const std::array<std::string, 30> nazwiska{ "Nowak", "Pawlak", "Moscicki", "Paderewski", "Matejko",
                                                    "Pilsudski", "Curie", "Wolski","Opel","Kosciuszko",
                                                    "Kreft", "Choinkowski", "Kupkowski", "Pietrzak", "Zimnoreczny",
                                                    "Glutkowski", "Borowiak", "Smarkowski", "Robakowski", "Slodkopyszczkowski",
                                                    "Winowski", "Ciosiowski", "Marszczynosek", "Babiowski", "Dziadziowski",
                                                     "Lialiowski", "Jajowski", "Swieczkowski", "Glupkowski", "Ossowski" };
        const std::array<std::string, 10> adres{"Szenwalda", "Wojska Polskiego", "Niemierzynska", "Mickiewicza", "Plac Rodla",
                                                "Plac Grunwaldzki", "Krzywoustego", "Konopnickiej", "Traugutta", "Poniatowskiego"};
        int year = std::rand()%120+1900;
        std::string month = std::to_string(std::rand()%12+1);
        if( std::stoi(month)<10 ){ month = "0" + month; }
        std::string  day = std::to_string(std::rand()%31+1);
        if( (std::stoi(month)== 4 || 6 || 9 || 11 )){day = std::to_string(std::rand()%30+1);}
        else if( std::stoi(month)==2 ){ day = std::to_string(std::rand()%28+1); }
        else if((std::stoi(month)==2)&&( ((year%4==0)&&(year%100!=0)) or (year%400==0) ) ){ day = std::to_string(std::rand()%29+1); }
        if( std::stoi(day)<10 ){ day = "0" + day;}
        std::string nnnnn = std::to_string(std::rand()%90000+9999);
        
        std::string name = imiona[std::rand()%10];
        std::string surname = nazwiska[std::rand()%30];
        std::string address = ( adres[std::rand()%10]) + " " + std::to_string(std::rand()%98+1 );
        int age = 2020-year;
        std::string pesel;
        if( year>=2010){ pesel = std::to_string(year-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn; }
        else if( (year>=2000)&&(year<2010) ){ pesel = "0" + std::to_string(year-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn ;}
        else if( (year>=1900)&&(year<1910) ) { pesel = "0" + std::to_string(year-1900) + month + day + nnnnn;}
        else { pesel = std::to_string(year-1900) + month + day + nnnnn;}
        std::string date_of_birth =std::to_string(year) + "." + month + "." + day;
       
        return Person(
            name,
            surname,
            address,
            age,
            pesel,
            date_of_birth,
            licznik++);
    }

    Person::~Person()=default;
