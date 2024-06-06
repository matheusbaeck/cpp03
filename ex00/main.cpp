/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:48 by math              #+#    #+#             */
/*   Updated: 2024/06/06 11:29:16 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	hero;

	hero = ClapTrap("Aquiles");
	hero.attack("Zombie");
	hero.takeDamege(9);
	for (size_t i = 0; i < 10; i++)
	{
		hero.beRepaired(1);
	}
	hero.attack("Zombie");
	hero.takeDamege(100);
	hero.beRepaired(100);

	return (0);
}
