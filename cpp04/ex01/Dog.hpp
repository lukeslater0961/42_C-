#ifndef	DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		void	create_brain(void);
		Brain*	get_brain(void) const;
		~Dog();
	
	private:
		Brain*	brain;
};

#endif
