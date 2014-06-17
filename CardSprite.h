#ifndef __CARDSPRITE_SCENE_H__
#define __CARDSPRITE_SCENE_H__

#include "cocos2d.h"

class CardSprite : public cocos2d::Sprite
{
public:
	//��ʼ������ֵ����ȣ��߶ȣ���ƬX�ᣬ��ƬY��
	static CardSprite* createCardSprite(int numbers,int width,int height,float CardSpriteX,float CardSpriteY);

	virtual bool init();

	CREATE_FUNC(CardSprite);

	//��ȡ����
	int getNumber();
	//��������
	void setNumber(int num);

private:
	//��ʾ�ڽ����е�����
	int number;
	void enemyInit(int numbers,int width,int height,float CardSpriteX,float CardSpriteY);

	//������ʾ���ֵĿؼ�
	cocos2d::LabelTTF* labelTTFCardNumber;

	//��ʾ����
	cocos2d::LayerColor* layerColorBG;
};

#endif // __CARDSPRITE_SCENE_H__

