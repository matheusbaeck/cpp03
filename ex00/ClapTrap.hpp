/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:01:44 by math              #+#    #+#             */
/*   Updated: 2024/06/05 18:46:48 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H__
# define CLAPTRAP_H__

#include <iostream>
#include <iomanip>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_atk;
	public:
		ClapTrap( std::string name );
		ClapTrap( void );
		~ClapTrap( void );
		void			attack(const std::string & target);
		void			takeDamege(unsigned int amout);
		void			beRepaired(unsigned int amout);
		/* Non Mandatory */
		bool			isAlive( void );
		bool			hasEnergy( void );
		// ClapTrap		&operator=(ClapTrap const &rhc);
};

#endif