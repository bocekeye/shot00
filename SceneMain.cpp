#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;

}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotFall)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		shot = nullptr;
	}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotFall)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotFall)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotFall)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		shot->draw();
	}
	//���݂��Ă���e�̐��̕\��
	int shotNum = 0;
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		if (shot->isExist()) shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Normal:%d", shotNum);
	shotNum = 0;
	for (auto& shot : m_pShotFall)
	{
		if (!shot) continue;
		if (shot->isExist()) shotNum++;
	}
	DrawFormatString(0, 30, GetColor(255, 255, 255), "Fall:%d", shotNum);
	shotNum = 0;
	for (auto& shot : m_pShotBound)
	{
		if (!shot) continue;
		if (shot->isExist()) shotNum++;
	}
	DrawFormatString(0, 60, GetColor(255, 255, 255), "Bound:%d", shotNum);

}

bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& shot : m_pShotNormal)
	{
		if (shot) continue;

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;

	}
	return false;
}
bool SceneMain::createShotFall(Vec2 pos)
{

	for (auto& shot : m_pShotFall)
	{
		if (shot) continue;

		shot = new ShotFall;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{

	for (auto& shot : m_pShotBound)
	{
		if (shot) continue;

		shot = new ShotBound;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;




}
#if false
	for (auto& shot : m_pShotNormal)
	{
		if (shot.isExist()) continue;

		shot.start(m_player.getPos());
		return true;
	}

	return false;
}
bool SceneMain::createShotFall(Vec2 pos)
{
	for (auto& shot : m_pShotFall)
	{
		if (shot.isExist()) continue;

		shot.start(m_player.getPos());
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& shot : m_pShotBound)
	{
		if (shot.isExist()) continue;

		shot.start(m_player.getPos());
		return true;
	}
	return false;
}
#endif