/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:48 by math              #+#    #+#             */
/*   Updated: 2024/06/07 17:43:06 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static int	attack(ScavTrap &agressor, ScavTrap &target)
{
	if (!agressor.isAlive())
		return (0);
	if (!agressor.hasEnergy())
	{
		std::cout << "-> Attack failure, " << agressor.getName() << " has no energy left" << std::endl;
		return (0);
	}
	if (!target.isAlive())
	{
		std::cout << "-> Attack failure, " << target.getName() << " is already dead" << std::endl;
		return (0);
	}
	agressor.attack(target.getName());
	target.takeDamege(agressor.getAtk());
	return (1);
}

static int	attack(ScavTrap &agressor, ClapTrap &target)
{
	if (!agressor.isAlive())
		return (0);
	if (!agressor.hasEnergy())
	{
		std::cout << "-> Attack failure, " << agressor.getName() << " has no energy left" << std::endl;
		return (0);
	}
	if (!target.isAlive())
	{
		std::cout << "-> Attack failure, " << target.getName() << " is already dead" << std::endl;
		return (0);
	}
	agressor.attack(target.getName());
	target.takeDamege(agressor.getAtk());
	return (1);
}

static int	attack(ClapTrap &agressor, ClapTrap &target)
{
	if (!agressor.isAlive())
		return (0);
	if (!agressor.hasEnergy())
	{
		std::cout << "-> Attack failure, " << agressor.getName() << " has no energy left" << std::endl;
		return (0);
	}
	if (!target.isAlive())
	{
		std::cout << "-> Attack failure, " << target.getName() << " is already dead" << std::endl;
		return (0);
	}
	agressor.attack(target.getName());
	target.takeDamege(agressor.getAtk());
	return (1);
}



int	main( void )
{
	std::string		hero_name = "Thor";
	unsigned int	hero_heal = 4;
	std::string		enemy_name = "Zazz";
	unsigned int	enemy_heal = 7;

	ScavTrap	hero(hero_name);
	std::cout << std::endl;
	
	ScavTrap	enemy;
	enemy = ScavTrap(enemy_name);
	std::cout << std::endl;

	ClapTrap	enemy2;
	enemy2 = ClapTrap("Clap");
	std::cout << std::endl;

	std::cout << hero << " initialized !!"<< std::endl;
	std::cout << enemy << " initialized !!" << std::endl;
	std::cout << enemy2 << " initialized !!" << std::endl;
	std::cout << std::endl;
	
	std::cout << "\t--START--" << std::endl << std::endl;
	while (hero.isAlive() && enemy2.isAlive() &&
			hero.hasEnergy() && enemy2.hasEnergy())
	{
		if (attack(hero, enemy2))
			enemy2.beRepaired(200);
		else
			break ;
		if (attack(enemy2, hero))
			hero.beRepaired(hero_heal);
	}
	std::cout << std::endl << "\t-- BOSS --" << std::endl << std::endl;
	if (enemy.getAtk() / 2 > hero_heal)
		hero.guardGate();
	while (hero.isAlive() && enemy.isAlive() &&
			hero.hasEnergy() && enemy.hasEnergy())
	{
		if (attack(hero, enemy))
			enemy.beRepaired(enemy_heal);
		else
			break ;
		if (attack(enemy, hero))
			hero.beRepaired(hero_heal);
	}
	std::cout << hero << std::endl;
	std::cout << enemy << std::endl;


	std::cout << std::endl << "\t--GAME OVER--" << std::endl << std::endl;
	return (0);
}