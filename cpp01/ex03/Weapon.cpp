#include "Weapon.hpp"
Weapon::Weapon(const std::string &type) : _type(type) {}
Weapon::~Weapon(){std::cout<< "destroyed weapon"<<std::endl;}
const std::string&	Weapon::getType() const{return (_type);}
void			Weapon::setType(const std::string &newWeaponType){_type = newWeaponType;}


