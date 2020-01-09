#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <memory>
#include <iterator>
#include <algorithm>
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
    Person() = default;
    Person( const std::string& _name, 
            const std::string& _surname,
            const std::string& _address, 
            const int& _age, 
            const std::string& _pesel,
            const std::string& _date_of_birth,
             int _licznik):
                name(_name), surname(_surname), address(_address),
                 age(_age), pesel(_pesel), date_of_birth(_date_of_birth), licznik(_licznik){}; 
    
    const std::string & get_name() const{return name;} 
    const std::string & get_surname() const{return surname;} 
    const std::string & get_address() const{return address;}  
    const int get_age() const{return age;} 
    const std::string get_date_of_birth() const{return date_of_birth;}  
    const std::string get_pesel() const{return pesel;}  
    const int get_licznik() const{return licznik;}

    friend std::ostream& operator<<(std::ostream& s,const Person & p)
    {
        s <<std::setw(10)<<std::left<<p.get_name()<<" "<<std::setw(18)<<std::left<<p.get_surname()<<" "<<std::setw(20)<<std::left<<p.get_address()<<" "
          <<std::setw(4)<<std::left<<p.get_age()<<" "<<std::setw(15)<<std::left<<p.get_pesel()<<std::setw(15)<<std::left<<p.get_date_of_birth()
          <<std::setw(12)<<std::left<<"licznik: "<<std::left<<p.get_licznik()<<"."<<std::endl;
        return s;
    };
    friend std::ostream& operator<<(std::ostream& r, std::pair<const std::string, std::shared_ptr<Person>> p)
    {
        r <<"Pesel->"<<p.first<<" "<<*p.second<<std::endl;
        return r;
    }

    Person get_random_person()
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
        
        name = imiona[std::rand()%10];
        surname = nazwiska[std::rand()%30];
        address = ( adres[std::rand()%10]) + " " + std::to_string(std::rand()%98+1 );
        age = 2020-year;
        if( year>=2010){ pesel = std::to_string(year-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn; }
        else if( (year>=2000)&&(year<2010) ){ pesel = "0" + std::to_string(year-2000) + std::to_string(std::stoi(month)+20) + day + nnnnn ;}
        else if( (year>=1900)&&(year<1910) ) { pesel = "0" + std::to_string(year-1900) + month + day + nnnnn;}
        else { pesel = std::to_string(year-1900) + month + day + nnnnn;}
        date_of_birth=std::to_string(year) + "." + month + "." + day;
        
        return Person(
            name,
            surname,
            address,
            age,
            pesel,
            date_of_birth,
            licznik++);
    }

    ~Person()=default;

    private:
    std::string name;
    std::string surname;
    std::string address;
    int age;
    std::string pesel;
    std::string date_of_birth;
    int licznik=1;
};
 


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


std::map<std::string, std::shared_ptr<Person>> baza;
    
std::multiset<std::shared_ptr<Person>, Comp_name > sort_name;
std::multiset<std::shared_ptr<Person>, Comp_surname> sort_surname;
std::multiset<std::shared_ptr<Person>, Comp_address> sort_address;
std::multiset<std::shared_ptr<Person>, Comp_age> sort_age;
std::multiset<std::shared_ptr<Person>, Comp_dob> sort_dob;
std::multiset<std::shared_ptr<Person>, Comp_licznik> sort_licznik;
template <class T>
void print_container(const T& container)
{
    for(auto& i: container)
    {
        std::cout<<*(i.second)<<std::endl;
    }
}

void get_data(const int type, const int start_position, const int amount)
{
    
    switch (type){
        case 0: 
            {
                print_container(baza);
                std::cout<<"######################################################\n";
            }     
        break;
        case 1:
            {
                for(auto it=baza.begin(); it!=baza.end(); ++it)
                {
                    sort_name.emplace((*it).second);
                }
                auto its = sort_name.begin();//
                int max_amount = sort_name.size()-start_position;
                for(std::advance(its,start_position);its!=(std::next(sort_name.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            } 
        break;
        case 2:
            {
            for(auto it=baza.begin(); it!=baza.end(); ++it)
                {
                    sort_surname.emplace((*it).second);
                }
                auto its = sort_surname.begin();
                for(std::advance(its,start_position);its!=(sort_surname.end()); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 3: 
            {
            for(auto it=baza.begin(); it!=baza.end(); ++it)
                {
                    sort_address.emplace((*it).second);
                }
                auto its = sort_address.begin();
                for(std::advance(its,start_position);its!=(sort_address.end()); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 4: 
            {
            for(auto it=baza.begin(); it!=baza.end(); ++it)
                {
                    sort_age.emplace((*it).second);
                }
                auto its = sort_age.begin();
                for(std::advance(its,start_position);its!=(sort_age.end()); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 5: 
            {
            for(auto it=baza.begin(); it!=baza.end(); ++it)
                {
                    sort_dob.emplace((*it).second);
                }
                auto its = sort_dob.begin();
                for(std::advance(its,start_position);its!=(sort_dob.end()); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        default: std::cout<<"pocałuj mnie :D";
        break;
    }
    
}
int main()
{
    std::srand(time(nullptr));
    Person s;
    
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
}# Loocas
