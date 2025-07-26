#include <ctime>
#include <iostream>
#include "Account.hpp"

using namespace std;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout	<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << endl;
}

Account::~Account()
{
	_displayTimestamp();
	cout	<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << endl;
}

int Account::getNbAccounts() { return (_nbAccounts); }
int Account::getTotalAmount() { return (_totalAmount); }
int Account::getNbDeposits() { return (_totalNbDeposits); }
int Account::getNbWithdrawals() { return (_totalNbWithdrawals); }
int Account::checkAmount() const { return (this->_amount); }

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	cout	<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount + deposit
			<< ";nb_deposits:" << _nbDeposits << endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount > withdrawal)
	{
		_displayTimestamp();
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << _nbWithdrawals << endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return true;
	}
	else
	{
		_displayTimestamp();
		cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused" << endl;
		return false;
	}
}

void Account::displayStatus() const
{
	_displayTimestamp();
	cout	<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << endl;
}

void Account::_displayTimestamp(void)
{
	char timestamp[20];
	time_t now;
	time(&now);
	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", localtime(&now));
	cout << "[" << timestamp << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout	<< "accounts:" << _nbAccounts
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << endl;
}
