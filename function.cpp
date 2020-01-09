#include <string>
#include <iostream>
#include <memory>

class PersonIf {
   public:
       virtual const std::string & get_name() const = 0;
};

class Person : public PersonIf {
    public:
        std::string s = {"dupa wolowa"};
        const std::string & get_name() const {return s;};

};

int main(){
    std::shared_ptr<PersonIf> p=std::make_shared<Person>();
    std::cout<<p->get_name();
    return 0;
}
