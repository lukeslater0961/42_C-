#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		void	create_brain(void);
		void	makeSound(void) const;
		Brain*	get_brain(void) const;
		~Cat();

	private:
		Brain*	brain;
};

#endif
