#include <iostream>
#include "Greeter.h"
using namespace std;

int main() 
{
    string name = "World";
    
    Greeter greeter(name);
    cout<<greeter.getGreeting()<<endl;

    greeter.setWelcomeMessage("Hola");
    cout<<greeter.getGreeting()<<endl;

    return 0;
}