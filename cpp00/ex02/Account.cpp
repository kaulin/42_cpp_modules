/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:11:10 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/02 11:15:39 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Use to check: ./BanksterPro > log.log && diff <(sed 's/\[[^][]*\]//g' 19920104_091532.log) <(sed 's/\[[^][]*\]//g' log.log)

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Private
Account::Account() {}

void	Account::_displayTimestamp( void ) {
	std::time_t	now = std::time(0);
	std::tm*	curTime = std::localtime(&now);
	std::cout << "["
		<< std::setw(4) << std::setfill('0') << curTime->tm_year +  1900
		<< std::setw(2) << std::setfill('0') << curTime->tm_mon
		<< std::setw(2) << std::setfill('0') << curTime->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << curTime->tm_hour
		<< std::setw(2) << std::setfill('0') << curTime->tm_min
		<< std::setw(2) << std::setfill('0') << curTime->tm_sec << "]";
}

// Construct
Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

// Destruct
Account::~Account() {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

// Get
int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

// Other

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	int	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	int	p_amount = _amount;
	if ( checkAmount() < withdrawal ) {
		std::cout
			<< " index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused" << std::endl;
			return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const { return _amount; }

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout 
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}