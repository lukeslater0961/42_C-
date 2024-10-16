#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit){_amount = initial_deposit; _accountIndex = 0; _nbDeposits = 0; _nbWithdrawals = 0;}
Account::~Account()
{
	std::cout << "index:"<< _accountIndex;
	std::cout << ";amount:"<< _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void){return (_nbAccounts);}
int	Account::getTotalAmount(void){return (_totalAmount);}
int	Account::getNbDeposits(void){return(_totalNbDeposits);}
int	Account::getNbWithdrawals(void){return(_totalNbWithdrawals);}



void	Account::makeDeposit(int deposit)
{
	std::cout << "amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _totalNbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << "p_amount:" << _amount;
	if (withdrawal <= 0 || ((_amount -= withdrawal) < 0))
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _totalNbWithdrawals << std::endl;
	return (true);
}
