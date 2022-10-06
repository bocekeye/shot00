#include "ShotBound.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	constexpr float kShotSpeed = 0.1f;

	//íµÇÀï‘ÇËâÒêî
	constexpr int kBoundMax = 3;

	constexpr int kSizeX = 16;
	constexpr int kSizeY = 16;
}

void ShotBound::start(Vec2 pos)
{
	ShotBase::start(pos);

	float randAngle = static_cast<float>(GetRand(359)); 
	float rad = randAngle * DX_PI_F / 180.0;       //ÉâÉWÉAÉìÇ…ïœä∑

	m_vec.x = cosf(rad) * kShotSpeed;
	m_vec.y = sinf(rad) * kShotSpeed;

// m_vec *= * kShotSpeed;

	m_BoundCount = 0;
}

void ShotBound::update()
{
	if (!m_isExist) return;

	m_pos += m_vec;

	if (m_BoundCount < kBoundMax)
	{

		if (m_pos.y < 0.0f)
		{
			m_vec.y *= -1;
			m_BoundCount++;
		}
		if (m_pos.y > Game::kScreenHeight - kSizeY)
		{
			m_vec.y *= -1;
			m_BoundCount++;
		}
		if (m_pos.x > Game::kScreenWidth - kSizeX)
		{
			m_vec.x *= -1;
			m_BoundCount++;
		}
		if (m_pos.x < 0.0f)
		{
			m_vec.x *= -1;
			m_BoundCount++;
		}
	}
	else
	{
		if (m_pos.x < (0 - kSizeX))
		{
			m_isExist = false;
		}
		if (m_pos.y < (0 - kSizeY))
		{
			m_isExist = false;
		}
		if (m_pos.x > Game::kScreenWidth)
		{
			m_isExist = false;
		}
		if (m_pos.y > Game::kScreenHeight)
		{
			m_isExist = false;
		}
		
	}
	
}
