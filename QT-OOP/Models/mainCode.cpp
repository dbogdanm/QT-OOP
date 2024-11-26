#include <iostream>
#include <array>
#include "Models/Route.h"
#include "Models/Driver.h"
#include "Models/Vehicle.h"
#include "Models/FleetManager.h"
#include "Models/Helper.h"
using namespace std;

int main()
{

vector<Driver> drivers = Helper::ReadDriverFromFile();
vector<Route> routes = Helper::ReadRouteFromFile();


for(int i = 0; i < drivers.size(); i++)
{
    cout << drivers[i] << endl;
    cout << endl;
}

for(int i = 0; i < routes.size(); i++)
{
    cout << routes[i] << endl;
    cout << endl;
}


}




