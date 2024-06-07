/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:01:44 by math              #+#    #+#             */
/*   Updated: 2024/06/07 17:57:20 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H__
# define SCAVTRAP_H__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guard;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap& operator=( ScavTrap const &rhc );
		~ScavTrap( void );
		void	guardGate();
		void	takeDamege( unsigned int amount );
};

#endif