#pragma once
class Stat
{
public:
	Stat(float max);
	
	float GetCurrent() { return m_current; }
	float GetMax() { return m_max; }

	void SetMax(float val) { m_max = val; }
	void SetCurrent(float val) { m_current = val; }
	void SetStatToMax() { m_current = m_max; }


private:
	float m_current;
	float m_max;
};

