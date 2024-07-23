/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:46:50 by math              #+#    #+#             */
/*   Updated: 2024/06/12 11:45:26 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->setHp (100);
	this->setEp(100);
	this->setAtk(30);
	std::cout<< "\tFrag " << this->getName() <<" std constructor called!" << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	this->setName(name);
	this->setHp (100);
	this->setEp(100);
	this->setAtk(30);
	std::cout<< "\tFrag " << this->getName() <<" constructor called!" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ) : ClapTrap()
{
	std::cout<< "\tFrag " << this->getName() <<" cpy constructor called!" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &rhc )
{
	if (this == &rhc)
		return (*this);
	this->setName(rhc.getName());
	this->setHp(rhc.getHp());
	this->setEp(rhc.getEp());
	this->setAtk(rhc.getAtk());
	std::cout << "\tFrag " << this->getName() <<" assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout<< "\tFrag " << this->getName() <<" destructor called!" << std::endl;
}

void	FragTrap::takeDamage( unsigned int amount )
{
	if (amount >= this->getHp())
		this->highFivesGuys();
	this->ClapTrap::takeDamage(amount);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "->" << " WELL DONE BROTHER, " << this->getName() << " requests a high five! ✋" << std::endl;
}
