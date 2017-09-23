#include "control.h"

CControl::CControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_listCommands({"TurnOn", bind(CControl::TurnOn())},
	{"TurnOff", bind(CControl::TurnOff())},
	{"SelectChannel", bind(CControl::SelectChannel())},
	{ "Info", bind(CControl::Info()) })
{
}

bool CControl::HandleCommands()
{
	string command;
	m_input >> command;

	auto it = m_listCommands.find(command);
	if (it != m_listCommands.end())
	{
		return it->second(m_input);
	}

	return false;
}

bool CControl::TurnOn()
{
	m_tv.TurnOn();
	m_output << "TV is successful turned on\n";
	return true;
}

bool CControl::TurnOff()
{
	m_tv.TurnOff();
	m_output << "TV is successful turned off\n";
	return true;
}

bool CControl::SelectChannel()
{
	int channel = 0;
	m_input >> channel;
	m_tv.SelectChannel(channel);
	m_output << "TV channel is successful changed\n";
	return true;
}

bool CControl::Info()
{
	m_output << m_tv.IsTurnedOn ? "TV is turned on\n" : "TV is turned off\n";
	m_output << m_tv.GetChannel() << "\n";
}