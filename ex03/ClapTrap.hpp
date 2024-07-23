/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:01:44 by math              #+#    #+#             */
/*   Updated: 2024/06/11 18:44:32 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H__
# define CLAPTRAP_H__

# include <iostream>
# include <iomanip>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_atk;
	protected:
		void			setName( std::string name );
		void			setHp( unsigned int amount );
		void			setEp( unsigned int amount );
		void			setAtk( unsigned int amount );
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & );
		ClapTrap& operator=( ClapTrap const &rhc );
		~ClapTrap( void );
		void			attack( const std::string & target );
		void			takeDamage( unsigned int amout );
		void			beRepaired( unsigned int amout );
		/* Non Mandatory */
		bool			isAlive( void ) const;
		bool			hasEnergy( void ) const;
		std::string		getName( void ) const;
		unsigned int	getHp( void ) const;
		unsigned int	getEp( void ) const;
		unsigned int	getAtk( void ) const;
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &obj);

#endif
