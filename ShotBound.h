#pragma once

#include "ShotBase.h"

//�p��
class ShotBound : public ShotBase
{
public:
	ShotBound()
	{
		m_BoundCount = 0;
	}
	virtual ~ShotBound() {};

	//�V���b�g�J�n
	virtual void start(Vec2 pos);

	// �X�V
	virtual void update();

private:
	int m_BoundCount;

};
