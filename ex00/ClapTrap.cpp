/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:46:50 by math              #+#    #+#             */
/*   Updated: 2024/06/07 14:03:45 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Nameless"), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Copy constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &)
{
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout<< "Destructor called!" << std::endl;
}

bool	ClapTrap::isAlive( void ) const
{
	if (this->_hp == static_cast<unsigned int>(0))
	{
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::hasEnergy( void ) const
{
	if (this->_ep == static_cast<unsigned int>(0))
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to ";
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string & target)
{
	if (!this->isAlive())
		return ;
	if (!this->hasEnergy())
	{
		std::cout << "attack!" << std::endl;
		return ;
	}
	this->_ep--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atk << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amout)
{
	if (!this->isAlive())
		return ;
	if (this->_hp > amout)
		this->_hp -= amout;
	else
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name << " received " << amout << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (!this->isAlive())
		return ;
	if (!this->hasEnergy())
	{
		std::cout << "repair!" << std::endl;
		return ;
	}
	this->_hp += amout;
	this->_ep--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amout << " points of Life!" << std::endl;
}
