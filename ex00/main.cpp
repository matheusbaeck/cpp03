/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:48 by math              #+#    #+#             */
/*   Updated: 2024/06/07 18:10:39 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	hero;

	hero = ClapTrap("Aquiles");
	hero.attack("Zombie");
	hero.takeDamage(9);
	for (size_t i = 0; i < 10; i++)
	{
		hero.beRepaired(1);
	}
	hero.attack(9999)
	hero.takeDamage(100);
	hero.beRepaired(100);

	return (0);
}
