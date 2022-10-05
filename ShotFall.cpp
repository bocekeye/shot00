#include "ShotFall.h"
#include "game.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
}

void ShotFall::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed;
	m_vec.y = -4.0f;

}

void ShotFall::update()
{
	if (!m_isExist) return;
	
	m_pos += m_vec;

	m_vec.y += 0.5f;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
