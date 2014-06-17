#include "HelloWorldScene.h"
#include "CardSprite.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();


	 

		//������Ϸ�ı�����ɫ
	auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180,170,160,255));
	this->addChild(layerColorBG);

	//������Ƭ  
    createCardSprite(visibleSize);

    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
    

    return true;
}



//�¼������ص���������ʼ
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	//��ȡ������X���Y��
	Point touchPoint = touch->getLocation(); //��ȡOpenGL���꣨��cocos2d-x���꣬ԭ�������½ǣ�
	touch->getLocationInView();
	firstX=touchPoint.x;
	firstY=touchPoint.y;

	return true;
}


//�¼������ص�����������
void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	//��ȡX���Y����ƶ���Χ
	Point touchPoint=touch->getLocation(); //��ȡOpenGL���꣨��cocos2d-x���꣬ԭ�������½ǣ�
	endX=firstX - touchPoint.x;
	endY=firstY - touchPoint.y;

	//�ж�X���Y����ƶ����룬���X��ľ���ֵ���������һ��������Y��ľ���ֵ���������»���
	if(abs(endX) > abs(endY))
	{
		//����������
		//�ж�����������
		if(endX+5>0)
		{
			//����
			doLeft();
		}
		else
		{
			//����
			doRight();
		}
	}
	else
	{
		//����������
		//�ж��������ϻ�������
		if(endY+5>0)
		{
			//����
			doDown();
		}
		else
		{
			//����
			doUp();
		}

	}
}



//�����������ҵķ���
bool HelloWorld::doUp()
{
	log("doUp");
	return true;
}

bool HelloWorld::doDown()
{
	log("doDown");
	return true;
}

bool HelloWorld::doLeft()
{
	log("doLeft");
	return true;
}

bool HelloWorld::doRight()
{
	log("doRight");
	return true;
}


//������Ƭ
void HelloWorld::createCardSprite(cocos2d::Size size)
{
	//�����Ԫ��Ŀ�Ⱥ͸߶�
	int unitSize = (size.height-28)/4;

	//4*4�ĵ�Ԫ��
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			CardSprite* card = CardSprite::createCardSprite(2, unitSize, unitSize, unitSize*i+140, unitSize*j+20);

			addChild(card);
		}
	}
}