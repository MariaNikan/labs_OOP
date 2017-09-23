#include "TVSet.h"
#include "stdafx.h"

bool CTVSet::IsTurnedOn()const
{
	return m_isTurnedOn;
}

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
}

int CTVSet::GetChannel()const
{
	return m_isTurnedOn ? m_selectedChannel : 0;
}

bool CTVSet::SelectChannel(int channel)
{
	if ((channel >= 1) && (channel <= 99))
	{
		m_selectedChannel = channel;
	}
	else
		return 1;
}