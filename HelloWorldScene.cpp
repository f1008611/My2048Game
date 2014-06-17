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


	 

		//加入游戏的背景颜色
	auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180,170,160,255));
	this->addChild(layerColorBG);

	//创建卡片  
    createCardSprite(visibleSize);

    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
    

    return true;
}



//事件监听回调：触摸开始
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	//获取触摸的X轴和Y轴
	Point touchPoint = touch->getLocation(); //获取OpenGL坐标（即cocos2d-x坐标，原点在左下角）
	touch->getLocationInView();
	firstX=touchPoint.x;
	firstY=touchPoint.y;

	return true;
}


//事件监听回调：触摸结束
void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	//获取X轴和Y轴的移动范围
	Point touchPoint=touch->getLocation(); //获取OpenGL坐标（即cocos2d-x坐标，原点在左下角）
	endX=firstX - touchPoint.x;
	endY=firstY - touchPoint.y;

	//判断X轴和Y轴的移动距离，如果X轴的绝对值大，则向左右滑动，如果Y轴的绝对值大，则向上下滑动
	if(abs(endX) > abs(endY))
	{
		//手势向左右
		//判断向左还是向右
		if(endX+5>0)
		{
			//向左
			doLeft();
		}
		else
		{
			//向右
			doRight();
		}
	}
	else
	{
		//手势向上下
		//判断手势向上还是向下
		if(endY+5>0)
		{
			//向下
			doDown();
		}
		else
		{
			//向上
			doUp();
		}

	}
}



//滑向上下左右的方法
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


//创建卡片
void HelloWorld::createCardSprite(cocos2d::Size size)
{
	//求出单元格的宽度和高度
	int unitSize = (size.height-28)/4;

	//4*4的单元格
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			CardSprite* card = CardSprite::createCardSprite(2, unitSize, unitSize, unitSize*i+140, unitSize*j+20);

			addChild(card);
		}
	}
}