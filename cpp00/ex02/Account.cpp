/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:11:10 by jajuntti          #+#    #+#             */
/*   Updated: 2024/11/01 16:39:38 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Use to check: diff <(sed 's/\[[^][]*\]//g' 19920104_091532.log) <(sed 's/\[[^][]*\]//g' log.log)

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
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
		<< curTime->tm_year +  1900
		<< curTime->tm_mon + 1
		<< curTime->tm_mday << "_"
		<< curTime->tm_hour
		<< curTime->tm_min
		<< curTime->tm_sec << "]";
//[19920104_091532]
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
//[19920104_091532] index:0;amount:42;created
}
// Destruct
Account::~Account() {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
//[19920104_091532] index:0;amount:47;closed
}
// Get
int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }
// Set

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
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
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
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
}

int		Account::checkAmount( void ) const { return _amount; }
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
}
void	Account::displayAccountsInfos( void ) {
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout 
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}