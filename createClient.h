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

    void askName();
    void askLastName();
    void askID();
    void askAge();
    void askPhoneNumber();
    void askEmail();
    void askAddress();
    void sumaryDate();
};
void createClients(std::vector<date> &clients);
#endif