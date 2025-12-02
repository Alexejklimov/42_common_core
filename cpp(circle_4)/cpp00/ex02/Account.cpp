/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:28:12 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/26 16:52:04 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit){
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;

	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	
	if(this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
          << ";p_amount:" << (this->_amount + withdrawal)
          << ";withdrawal:" << withdrawal
          << ";amount:" << this->_amount
          << ";nb_withdrawals:" << this->_nbWithdrawals
          << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
			      << ";amount:" << this->_amount
			      << ";refused" << std::endl;
	}
	return false;
	
}

int Account::checkAmount( void )const{
	return(this->_amount);
}

void Account::displayStatus( void )const{
	 _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	char buf[20];
	std::tm *lt = std::localtime(&t);
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", lt);
	std::cout << buf << " ";
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}
int	Account::getTotalAmount( void ){
	return (_totalAmount);
}
int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}