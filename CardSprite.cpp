#include "CardSprite.h"
USING_NS_CC;

//ʵ�ֻ�����ģ��
CardSprite* CardSprite::createCardSprite(int numbers,int width,int height,float CardSpriteX,float CardSpriteY)
{
	CardSprite* enemy = new CardSprite();
	if(enemy && enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(numbers, width, height, CardSpriteX, CardSpriteY);

		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return NULL;
}

//��ʼ��
bool CardSprite::init()
{
	if(!Sprite::init())
	{
		return false;
	}

	return true;
}


void CardSprite::enemyInit(int numbers,int width,int height,float CardSpriteX,float CardSpriteY)
{
	//���ó�ʼ��ֵ
	number = numbers;

	//������Ϸ�ı�����ɫ
	layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(200,190,180,255),width-15,height-15);
	layerColorBG->setPosition(Point(CardSpriteX,CardSpriteY));

	//�ж��������0����ʾ��������ʾ��
	if(number > 0)
	{
		//�����м�����
		auto labelTTFCardNumber = LabelTTF::create(String::createWithFormat("%i",number)->getCString(),"Arial",100);
		labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
		labelTTFCardNumber->setTag(8);
		layerColorBG->addChild(labelTTFCardNumber);
	}
	else
	{
		//�����м�����
	    auto labelTTFCardNumber = LabelTTF::create("","Arial",100);
		labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width/2,layerColorBG->getContentSize().height/2));
		labelTTFCardNumber->setTag(8);
		layerColorBG->addChild(labelTTFCardNumber);

	}

	this->addChild(layerColorBG);
}


//��ȡ����
int CardSprite::getNumber()
{
	return number;
}

//��������
void CardSprite::setNumber(int num)
{
	number = num;

	if(number > 0)
	{
		//��ȡ�������¸�������
		labelTTFCardNumber->setString(String::createWithFormat("%i",number)->getCString());
	}
	else
	{
		labelTTFCardNumber->setString("");
	}
}
