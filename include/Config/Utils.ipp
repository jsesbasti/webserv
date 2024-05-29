/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:48:52 by jsebasti          #+#    #+#             */
/*   Updated: 2024/05/29 22:13:36 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_IPP__
# define __UTILS_IPP__

# include <Utils.hpp>

namespace SUtils {
	template <typename T>
	int	easyfind( typename T::iterator begin, typename T::iterator end, std::string toFind ) {
		typename T::iterator	it;

		it = begin; 
		while ( it != end && *it != toFind )
			it++;
		if ( it == end )
			return ( -1 );
		return ( it - begin );
	}
};

namespace std {
	template <typename T>
	string	to_string( const T &n ) {
		ostringstream ss;

		ss << n;
		return (ss.str());
	}
};

#endif
