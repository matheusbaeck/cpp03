/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DimondTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:37:12 by math              #+#    #+#             */
/*   Updated: 2024/06/12 10:41:37 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DimondTrap.hpp"

DimondTrap::DimondTrap( void ) : _name("DiamondTrap")
{
	this->ScavTrap::setHp (100);
	this->ScavTrap::setEp(50);
	this->ScavTrap::setAtk(30);
	std::cout<< "\tDimond " << this->ScavTrap::getName() <<" cpy constructor called!" << std::endl;
}

DimondTrap::DimondTrap( std::string name ) : _name("DiamondTrap")
{
	this->ScavTrap::setName(name);
	this->ScavTrap::setHp (100);
	this->ScavTrap::setEp(50);
	this->ScavTrap::setAtk(30);
	std::cout<< "\tDimond " << this->ScavTrap::getName() <<" constructor called!" << std::endl;
}

DimondTrap &DimondTrap::operator=(DimondTrap const &rhc )
{
	if (this == &rhc)
		return (*this);
	this->_name = "DiamondTrap";
	this->ScavTrap::setName(rhc.ScavTrap::getName());
	this->ScavTrap::setHp(rhc.ScavTrap::getHp());
	this->ScavTrap::setEp(rhc.ScavTrap::getEp());
	this->ScavTrap::setAtk(rhc.ScavTrap::getAtk());
	std::cout << "\tDimond " << this->ScavTrap::getName() <<" assignment operator called" << std::endl;
	return (*this);
}

DimondTrap::~DimondTrap( void )
{
	std::cout<< "\tDimond " << this->ScavTrap::getName() <<" destructor called!" << std::endl;
}

void	DimondTrap::takeDamage( unsigned int amount )
{
	if (amount >= this->ScavTrap::getHp())
		this->highFivesGuys();
	this->ScavTrap::takeDamage(amount);
}

void	DimondTrap::whoAmI( void )
{
	std::cout << "-> I AM... THE DIMOND... I AM " << this->getName() <<std::endl;
}

std::string		DimondTrap::getName( void ) const
{
	return (this->_name + "_" + this->ClapTrap::getName());
}

std::ostream	&operator<<(std::ostream &os, DimondTrap const &obj)
{
	os << obj.getName() << " " << obj.getHp() << "/" << obj.getEp();
	return (os);
}
