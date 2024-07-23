/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DimondTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:01:44 by math              #+#    #+#             */
/*   Updated: 2024/06/11 18:49:30 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIMONDTRAP_H__
# define DIMONDTRAP_H__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DimondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DimondTrap( void );
		DimondTrap( std::string name );
		DimondTrap( DimondTrap const & );
		DimondTrap& operator=( DimondTrap const &rhc );
		~DimondTrap( void );
		void			takeDamage( unsigned int amount );
		void			whoAmI( void );
		std::string		getName( void ) const;
};

std::ostream	&operator<<(std::ostream &os, DimondTrap const &obj);

#endif
