/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:01:44 by math              #+#    #+#             */
/*   Updated: 2024/06/07 18:10:39 by math             ###   ########.fr       */
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
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap& operator=( ClapTrap const &rhc );
		~ClapTrap( void );
		void			attack( const std::string & target );
		void			takeDamage( unsigned int amout );
		void			beRepaired( unsigned int amout );
		/* Non Mandatory */
		bool			isAlive( void ) const;
		bool			hasEnergy( void ) const;
};

#endif