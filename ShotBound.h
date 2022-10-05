#pragma once

#include "ShotBase.h"

//継承
class ShotBound : public ShotBase
{
public:
	ShotBound()
	{
		m_BoundCount = 0;
	}
	virtual ~ShotBound() {};

	//ショット開始
	virtual void start(Vec2 pos);

	// 更新
	virtual void update();

private:
	int m_BoundCount;

};
