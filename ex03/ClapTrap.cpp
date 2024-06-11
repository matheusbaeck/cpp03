/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:46:50 by math              #+#    #+#             */
/*   Updated: 2024/06/11 18:33:52 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Nameless"), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Clap " << this->_name << " copy constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout<< "Clap " << this->_name << " constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhc )
{
	if (this == &rhc)
		return (*this);
	this->_name = rhc._name;
	this->_hp = rhc._hp;
	this->_ep = rhc._ep;
	this->_atk = rhc._atk;
	std::cout << "Clap " << this->_name << " assignment operator called" << this->_name << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout<< "Clap " << this->_name << " destructor called!" << std::endl;
}

unsigned int	ClapTrap::getHp( void ) const
{
	return (this->_hp);
}

unsigned int	ClapTrap::getEp( void ) const
{
	return (this->_ep);
}

unsigned int	ClapTrap::getAtk( void ) const
{
	return (this->_atk);
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHp( unsigned int amount )
{
	if (amount == 0)
		std::cout << "trying to set invalid HP" << std::endl;
	this->_hp = amount;
}

void	ClapTrap::setEp( unsigned int amount )
{
	if (amount == 0)
		std::cout << "trying to set invalid EP" << std::endl;
	this->_ep = amount;
}

void	ClapTrap::setAtk( unsigned int amount )
{
	this->_atk = amount;
}

bool	ClapTrap::isAlive( void ) const
{
	if (this->_hp == static_cast<unsigned int>(0))
	{
		std::cout << "->WARNING: " << this->_name << " is dead!" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::hasEnergy( void ) const
{
	if (this->_ep == static_cast<unsigned int>(0))
	{
		std::cout << "->WARNING: " << this->_name << " has no energy left to ";
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
	std::cout << "-> " << this->_name << " attacks " << target << ", causing " << this->_atk << " points of damage!" << std::endl;
	std::cout << "-> " << this->_name << " has " << this->_ep << " energy points left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (!this->isAlive())
		return ;
	if (this->_hp > amout)
		this->_hp -= amout;
	else
		this->_hp = 0;
	std::cout << "-> " << this->_name << " received " << amout << " points of damage!" << std::endl;
	std::cout << "-> " << this->_name << " has " << this->_hp << " life points left." << std::endl;

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
	std::cout << "-> " << this->_name << " repaired " << amout << " points of Life!" << std::endl;
	std::cout << "-> " << this->_name << " has " << this->_hp << " life points left and " << this->_ep << " energy points left." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &obj)
{
	os << obj.getName() << " " << obj.getHp() << "/" << obj.getEp();
	return (os);
}