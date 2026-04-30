#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "Cities.h"
#include "LinkedList.h"

// TODO(student): implement the dispatch scheduler
int route_length(const LinkedList& schedule){
    if(schedule.empty()){
        return 0;
    }
    int total =schedule.at(0);
    for(unsigned i =1;i<schedule.size();++i){
        int previous =schedule.at(i-1);
        int current =schedule.at(i);
        total+=previous>current?previous-current:current-previous;
    }
    int last =schedule.at(schedule.size()-1);
    total+=last;
    return total;
}
void print_schedule(const LinkedList& schedule){
    if(schedule.empty()){
        std::cout<<"The schedule is empty."<<std::endl;
        return;
    }
    for(unsigned i=0;i<schedule.size();++i){
        std::cout<<CityToString(static_cast<City>(schedule.at(i)))<< " -> ";
    }
    std::cout<<". ("<<route_length(schedule)<<")"<<std::endl;
}
std::string city_name_from_line(const std::string& line,const std::string& command){
    if(line.size()<=command.size()){
        return "";
    }
    std::string city_name=line.substr(command.size());
    while(!city_name.empty()&&city_name.front()==' '){
        city_name.erase(0,1);
    }
    return city_name;
}
void push_city(LinkedList& schedule, City city){
    if(city ==Unknown){
        std::cout<<"Unknown city."<<std::endl;
        return;
    }
    if(!schedule.empty()&&schedule.front()==city){
        return;
    }
    schedule.add(city,0);
}
void add_city(LinkedList& schedule,City city){
    if(city==Unknown){
        std::cout<<"Unknown city."<<std::endl;
        return;
    }
    unsigned index=0;
    while(index<schedule.size()&&schedule.at(index)<city){
        ++index;
    }
    if(index>0&&schedule.at(index-1)==city){
        return;
    }
    if(index <schedule.size() &&schedule.at(index) ==city){
        return;
    }
    schedule.add(city,index);
}
void remove_city(LinkedList& schedule,City city,const std::string& city_name){
    if(city==Unknown){
        std::cout<<"Unknown city."<<std::endl;
        return;
    }
    for(unsigned i=0;i<schedule.size();++i){
        if(schedule.at(i)==city){
            schedule.remove(i);
            return;
        }
    }
    std::cout<<city_name<<" is not on the schedule."<<std::endl;
}
int main(){
    LinkedList schedule;
    std::string line;

    while(std::getline(std::cin,line)){
        std::istringstream stream(line);
        std::string command;
        stream>>command;
        if(command=="push"){
            std::string city_name=city_name_from_line(line,command);
            push_city(schedule,StringToCity(city_name));
        }else if(command =="pop"){
            if(schedule.empty()){
                std::cout << "Cannot pop from an empty schedule." << std::endl;
            }else{
                schedule.remove(0);
            }
        }else if(command=="add"){
            std::string city_name =city_name_from_line(line,command);
            add_city(schedule,StringToCity(city_name));
        }else if(command =="remove"){
            std::string city_name=city_name_from_line(line,command);
            remove_city(schedule,StringToCity(city_name),city_name);
        }else if(command=="print"){
            print_schedule(schedule);
        }else if(command =="clear"){
            schedule.clear();
        }else if(command=="quit"){
            break;
        }else{
            std::cout<<"Unknown command."<<std::endl;
        }
    }
    return 0;
}
