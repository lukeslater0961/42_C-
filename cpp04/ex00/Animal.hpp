#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <string>
#include <iostream>

class	Animal{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		
		std::string	getType(void) const;
		void		setType(std::string Type);
		virtual void		makeSound(void) const;
		virtual	~Animal();
	protected:
		std::string type;
};

#endif
