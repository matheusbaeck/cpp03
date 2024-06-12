/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:48 by math              #+#    #+#             */
/*   Updated: 2024/06/12 12:04:59 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DimondTrap.hpp"

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
	target.takeDamage(agressor.getAtk());
	return (1);
}

static int	attack(ClapTrap &agressor, ScavTrap &target)
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
	target.takeDamage(agressor.getAtk());
	return (1);
}

static int	attack(ClapTrap &agressor, FragTrap &target)
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
	target.takeDamage(agressor.getAtk());
	return (1);
}

static int	attack(ClapTrap &agressor, DimondTrap &target)
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
	target.takeDamage(agressor.getAtk());
	return (1);
}

int	main( void )
{
	std::string		enemy_name = "Zombie";
	unsigned int	enemy_heal = 9;
	std::string		hero_name = "Thor";
	unsigned int	hero_heal = 9;
	std::string		miniboss_name = "Zazz";
	unsigned int	miniboss_heal = 12;
	std::string		boss_name = "Al Capone";
	unsigned int	boss_heal = 12;

	ClapTrap	enemy;
	enemy = ClapTrap(enemy_name);
	std::cout << std::endl;

	ScavTrap	hero;
	hero = ScavTrap(hero_name);
	std::cout << std::endl;
	
	FragTrap	miniboss;
	miniboss = FragTrap(miniboss_name);
	std::cout << std::endl;

	DimondTrap	boss;
	boss = DimondTrap(boss_name);
	std::cout << std::endl;

	std::cout << hero << " initialized !!"<< std::endl;
	std::cout << miniboss << " initialized !!" << std::endl;
	std::cout << enemy << " initialized !!" << std::endl;
	std::cout << boss << " initialized !!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "\t--START--" << std::endl << std::endl;
	std::cout << hero << std::endl;
	std::cout << enemy << std::endl;
	while (hero.isAlive() && enemy.isAlive() &&
			hero.hasEnergy() && enemy.hasEnergy())
	{
		if (attack(hero, enemy))
			enemy.beRepaired(enemy_heal);
		else
			break ;
		if (attack(enemy, hero))
			hero.beRepaired(hero_heal);
		std::cout << hero << std::endl;
		std::cout << enemy << std::endl;
	}

	std::cout << std::endl << "\t-- MINI BOSS --" << std::endl << std::endl;
	std::cout << hero << std::endl;
	std::cout << miniboss << std::endl;
	if (miniboss.getAtk() / 2 > hero_heal)
		hero.guardGate();
	while (hero.isAlive() && miniboss.isAlive() &&
			hero.hasEnergy() && miniboss.hasEnergy())
	{
		if (attack(hero, miniboss))
			miniboss.beRepaired(miniboss_heal);
		else
			break ;
		if (attack(miniboss, hero))
			hero.beRepaired(hero_heal);
		std::cout << hero << std::endl;
		std::cout << miniboss << std::endl;
	}

	std::cout << std::endl << "\t-- THE BOSS --" << std::endl << std::endl;
	std::cout << hero << std::endl;
	std::cout << boss << std::endl;
	boss.whoAmI();
	boss.highFivesGuys();
	boss.guardGate();
	while (hero.isAlive() && boss.isAlive() &&
			hero.hasEnergy() && boss.hasEnergy())
	{
		if (attack(hero, boss))
			boss.beRepaired(boss_heal);
		else
			break ;
		if (attack(boss, hero))
			hero.beRepaired(hero_heal);
		std::cout << hero << std::endl;
		std::cout << boss << std::endl;
	}


	std::cout << std::endl << "\t--GAME OVER--" << std::endl << std::endl;
	return (0);
}
