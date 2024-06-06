/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:46:50 by math              #+#    #+#             */
/*   Updated: 2024/06/06 11:34:12 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Contructor called!" << std::endl;
}

ClapTrap::ClapTrap( void ) : _name("Nameless"), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Copy contructor called!" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout<< "Destructor called!" << std::endl;
}

// std::ostream	&operator<<(std::ostream &os, ClapTrap const &obj)
// {
// 	os << obj._name;
// 	return (os);
// }

bool	ClapTrap::isAlive( void )
{
	if (this->_hp == static_cast<unsigned int>(0))
	{
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::hasEnergy( void )
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
	std::cout << "ClapTrap " << this->_name << " recived " << amout << " points of damage!" << std::endl;
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
