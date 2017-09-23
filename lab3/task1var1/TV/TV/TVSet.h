#pragma once
class CTVSet
{
public:
	bool IsTurnedOn()const;
	int GetChannel()const;
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
private:
	bool m_isTurnedOn = false;
	int m_selectedChannel = 1;
};

