/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:16:42 by rjobert           #+#    #+#             */
/*   Updated: 2024/03/28 16:09:42 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int argc, char *argv[])
{
	testConf test;
	test.host = "0"; test.port = "4242"; test.serverName = "testing Server";
	try
	{
		
		Server serv(test);
		serv.handleConnection();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// HERE THE BASE CONF FILE TO TEST
// server
// {
// 	listen	0:4242;

// 	location /
// 	{
// 		allow_methods	GET;
// 		autoindex		on;
// 		index			siege.html;
// 	}
// }