/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:46:50 by math              #+#    #+#             */
/*   Updated: 2024/06/07 18:10:39 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	this->setHp (100);
	this->setEp(50);
	this->setAtk(20);
	this->_guard = false;
	std::cout<< "\tScav " << this->getName() <<" std constructor called!" << std::endl;
}

ScavTrap::ScavTrap( std::string name )
{
	this->setName(name);
	this->setHp (100);
	this->setEp(50);
	this->setAtk(20);
	this->_guard = false;
	std::cout<< "\tScav " << this->getName() <<" constructor called!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap()
{
	std::cout<< "\tScav" << this->getName() << " cpy constructor called!" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhc )
{
	if (this == &rhc)
		return (*this);
	this->setName(rhc.getName());
	this->setHp(rhc.getHp());
	this->setEp(rhc.getEp());
	this->setAtk(rhc.getAtk());
	this->_guard = rhc._guard;
	std::cout << "\tScav " << this->getName() <<" assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout<< "\tScav " << this->getName() <<" destructor called!" << std::endl;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	unsigned int ep;

	ep = this->getEp();
	if (!this->_guard)
		this->ClapTrap::takeDamage(amount);
	else if (ep >= 2)
	{
		this->setEp(ep - 1);
		std::cout << "-> "<< this->getName() << " blocked " << (amount - (amount /2)) << " points of damage on Gate keeper mode!" << std::endl;
		std::cout << "-> " << this->getName() << " has " << this->getEp() << " energy points left." << std::endl;
		this->ClapTrap::takeDamage(amount / 2);
	}
	else
	{
		this->guardGate();
		this->takeDamage(amount);
	}
}

void	ScavTrap::guardGate( void )
{
	this->_guard = !this->_guard;
	if (this->_guard)
		std::cout << "-> " << this->getName() << " ScavTrap is now in Gate keeper mode on." << std::endl;
	else
		std::cout << "-> " << this->getName() << " ScavTrap is now in Gate keeper mode off." << std::endl;
}
