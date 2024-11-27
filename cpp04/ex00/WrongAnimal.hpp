#ifndef	WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <string>
#include <iostream>

class	WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		
		std::string	getType(void) const;
		void		setType(std::string Type);
		void		makeSound(void) const;
		virtual	~WrongAnimal();
	protected:
		std::string type;
};

#endif
