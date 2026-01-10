#pragma once
#include <string>

using namespace std;

class Greeter
{
public:
    Greeter(string g);
    void setWelcomeMessage(string w);
    string getGreeting();
private:
    string welcomeMessage;
    string greetee;
};
