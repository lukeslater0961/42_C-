#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);

		std::string	getType(void) const;
		void		setType(std::string Type);
		
		virtual void makeSound(void) const = 0;

		virtual ~AAnimal();
	protected:
		std::string type;
};

#endif
