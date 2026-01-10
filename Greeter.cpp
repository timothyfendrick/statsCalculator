#include <iostream>
#include "Greeter.h"

using namespace std;

Greeter::Greeter(string g)
{
    welcomeMessage = "Hello";
    greetee = g;
}
//--
void Greeter::setWelcomeMessage(string w)
{
    welcomeMessage = w;
}
//--
string Greeter::getGreeting()
{
    return welcomeMessage + " " + greetee + "!!!";
}