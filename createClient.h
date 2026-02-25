#ifndef CREATECLIENT_H
#define CREATECLIENT_H

#include <vector>
#include <string>
//dates necesary for the client
struct date
{
    std::string name;     
    std::string lastName;   
    long long int id;
    int age;
    long long int phoneNumber;
    std::string email;
    std::string address;
};
void createClients(std::vector<date> &personas);
#endif