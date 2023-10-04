#include <iostream>
#include <string>
#include "ennemi.h"
#include "link.h"
using namespace std;

ennemi::ennemi(string n,int v):name(n),vie(v){}

bois::bois():ennemi("pantin en bois",vie){}

fer::fer():ennemi("pantin en fer",vie){}

acier::acier():ennemi("pantin en acier",vie){}
