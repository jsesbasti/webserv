/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:33:38 by jsebasti          #+#    #+#             */
/*   Updated: 2024/05/06 20:08:22 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"

Location::Location( void ) : _uri("/") {
    return ;
}

Location::~Location( void ) {
    if (this->_d != NULL)
		delete this->_d;
	this->_d = NULL;
    return ;
}

Location::Location( const Location & src ) {
	*this = src;
}

Location	&Location::operator=( const Location & src ) {
	if (this != &src)
	{
		this->_d = new Directives(*src._d);
		this->_uri = src.getUri();
		this->_isDir = src._isDir;
	}
	return (*this);
}

const std::string   &Location::getUri( void ) const {
    return (this->_uri);
}

void                Location::setUri( const std::string & uri ) {
    this->_uri = uri;
}

void				Location::parse_location_line( const std::string &line ) {
	StrVector sline;

	sline = SUtils::split(sline, line, " \t\n");
	size_t len = sline.size();
	if (len != 3)
		throw std::logic_error("Unexpected amount of arguments. Expected \"location /uri/ {\"");
	this->_uri = sline[1];
	if (this->_uri[this->_uri.length() - 1] == '/')
		this->_isDir = true;
	else
		this->_isDir = false;
}

void    Location::parse( Directives *d, const std::string & content ) {
    StrVector line;
	StrVector lines;
    this->_d = new Directives(*d);

	lines = SUtils::split(lines, content, "\n");
	int len = lines.size();
	for (int i = 1; i < len; i++)
	{
		std::string treated_line = SUtils::treat_comments(lines[i]);
		line = SUtils::split(line, treated_line, " \t");
		if (!line[0].compare("{") || !line[0].compare("}"))
			continue ;
		int type = ParseContent::getLocAllowDirectives(line[0]);
		ParseDirectives::parseLocationDirectives( this->_d, line, type );
		line.clear();
        treated_line.clear();
	}
	if (!this->_d->alias.empty())
		this->_uri = this->_d->alias;
}

const UintStrMap::mapped_type			&Location::getErrorPage( unsigned int error_code ) const {
	return (this->_d->getErrorPage(error_code));
}