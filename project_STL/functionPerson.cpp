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
        
        int year_in = std::rand()%120+1900;
        int month_in = std::rand()%12+1; 
        int day_in;

        if((month_in==2)&&( ((year_in%4==0)&&(year_in%100!=0)) || (year_in%400==0) ) ){ day_in = std::rand()%29+1; }
        else if ( month_in==2 ){ day_in = std::rand()%28+1;}
        else if( (month_in == 4 || month_in == 6 || month_in == 9 || month_in == 11 )){day_in = std::rand()%30+1;}
        else  day_in = std::rand()%31+1; 

        std::string name = imiona[std::rand()%10];
        std::string surname = nazwiska[std::rand()%30];
        std::string address = ( adres[std::rand()%10]) + " " + std::to_string(std::rand()%98+1 );

        int age = 2020-year_in;

        std::string month;
        std::string day; 
        if( month_in<10 ){ month = "0" + std::to_string(month_in);} else { month = std::to_string(month_in); }
        if( day_in<10 ){ day = "0" + std::to_string(day_in);} else { day = std::to_string(day_in);}
        std::string nnnnn;
        int random = std::rand()%99999;
        if(random<10){ nnnnn = "0000" + std::to_string(random);}
        else if(random<100){ nnnnn = "000" + std::to_string(random);}
        else if(random<1000){ nnnnn = "00" + std::to_string(random);}
        else if(random<10000){ nnnnn = "0" + std::to_string(random);}
        else nnnnn = std::to_string(random);

        std::string pesel;

        if( year_in>=2010 ){ pesel = std::to_string(year_in-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn; }
        else if( (year_in>=2000)&&(year_in<2010) ){ pesel = "0" + std::to_string(year_in-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn ;}
        else if( (year_in>=1900)&&(year_in<1910) ) { pesel = "0" + std::to_string(year_in-1900) + month + day + nnnnn;}
        else { pesel = std::to_string(year_in-1900) + month + day + nnnnn;}
        std::string date_of_birth =std::to_string(year_in) + "." + month + "." + day;
       
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
