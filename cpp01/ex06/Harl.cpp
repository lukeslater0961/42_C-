#include "Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){std::cout << "\033[31mHarl destroyed\033[00m" << std::endl;};

void	Harl::debug(void)
{
	std::cout << "I love having a fence for my secondary command buffer for my compute pipelines in vulkan !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Did you know that Unity exposes a rendering API to the user through the commandBuffer class ?" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "How dare you not use simd's to optimise your code !!!!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "This code doesn't include any of the previously stated tools" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*actions[])(void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (unsigned int i = 0; i < (sizeof(levels) / sizeof(levels[0])) ;i++)
	{
		if (level == levels[i])
		{
			/*(this->*actions[i])();
			for (unsigned int j = i + 1; j < (sizeof(levels) / sizeof(levels[0])); j++)
				(this->*actions[j])();
			return ;*/
			switch (i) {
				case 0 :
					(this->*actions[0])();
				case 1 :
					(this->*actions[1])();
				case 2 :
					(this->*actions[2])();
				case 3 :
					{
						(this->*actions[3])();
						break;
					}
			}
			break;
		}
		else
		{
			std::cout << "no matching level found" << std::endl;
			break;
		}
	}
}
