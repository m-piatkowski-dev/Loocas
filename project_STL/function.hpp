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
    std::multiset<std::shared_ptr<Person>, Comp_licznik> sort_licznik;

    int start_position_new = start_position-1;
    
    switch (type){
        case 0: 
            {
                auto its = container.begin();
                int max_amount = container.size()-start_position_new;
                
                for(std::advance(its,start_position_new);its!=(std::next(container.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*its->second<<std::endl;
                } 
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
                int max_amount = sort_name.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_name.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            } 
        break;
        case 2:
            {
            for(auto it=container.begin(); it!=container.end(); ++it)
                {
                    sort_surname.emplace((*it).second);
                }
                auto its = sort_surname.begin();
                int max_amount = sort_surname.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_surname.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 3: 
            {
            for(auto it=container.begin(); it!=container.end(); ++it)
                {
                    sort_address.emplace((*it).second);
                }
                auto its = sort_address.begin();
                int max_amount = sort_address.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_address.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 4: 
            {
            for(auto it=container.begin(); it!=container.end(); ++it)
                {
                    sort_age.emplace((*it).second);
                }
                auto its = sort_age.begin();
                int max_amount = sort_age.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_age.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 5: 
            {
            for(auto it=container.begin(); it!=container.end(); ++it)
                {
                    sort_dob.emplace((*it).second);
                }
                auto its = sort_dob.begin();
                int max_amount = sort_dob.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_dob.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        case 6: 
            {
            for(auto it=container.begin(); it!=container.end(); ++it)
                {
                    sort_licznik.emplace((*it).second);
                }
                auto its = sort_licznik.begin();
                int max_amount = sort_licznik.size()-start_position_new;
                for(std::advance(its,start_position_new);its!=(std::next(sort_licznik.end(),-(max_amount-amount))); ++its)
                {
                    std::cout<<*(*its)<<std::endl;
                } 
                std::cout<<"######################################################\n";
            }
        break;
        default: std::cout<<"default :D";
        break;
    }
    
}

