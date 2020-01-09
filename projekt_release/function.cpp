#include "projekt_r.hpp"
#include "struktury.hpp"
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <memory>
#include <iterator>
#include <algorithm>



template <class T>
void print_container(const T& container)
{
    for(auto& i: container)
    {
        std::cout<<*(i.second)<<std::endl;
    }
}
template <class T>
void get_data( T& container,const int type, const int start_position, const int amount)
{
    std::multiset<std::shared_ptr<Person>, Comp_name > sort_name;
    std::multiset<std::shared_ptr<Person>, Comp_surname> sort_surname;
    std::multiset<std::shared_ptr<Person>, Comp_address> sort_address;
    std::multiset<std::shared_ptr<Person>, Comp_age> sort_age;
    std::multiset<std::shared_ptr<Person>, Comp_dob> sort_dob;
    
    switch (type){
        case 0: 
            {
                print_container(container);
                std::cout<<"######################################################\n";
            }     
        break;
        case 1:
            {
                for(auto it=container.begin(); it!=container.end(); ++it)
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
        break;/*
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
        break;*/
    }
}