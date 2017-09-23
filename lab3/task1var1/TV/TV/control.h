#pragma once

#include "stdafx.h"
#include "TVSet.h"
#include <boost/noncopyable.hpp>

class CTVSet;

class CControl : boost::noncopyable
{
public:
	CControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommands();

private:
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel();
	bool Info();

	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;
	std::map < std::string, std::function<bool()>> m_listCommands;
};
