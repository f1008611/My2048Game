#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"
#include "CardSprite.h"

class HelloWorld : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();  
    
    CREATE_FUNC(HelloWorld);

	//在这里加入手势识别的事件检测
    //监听事件回调：触摸开始和触摸结束
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
 
    //滑向上下左右的方法
    bool doUp();
    bool doDown();
    bool doLeft();
    bool doRight();

		//创建卡片
	void createCardSprite(cocos2d::Size size);
		//自动生成卡片
	void autoCreateCardNumber();

		//判断游戏是否还能继续
	void doCheckGameOver();
 
private:
    //点击元素
    int firstX,firstY,endX,endY;
	//创建一个卡片二位数组
	CardSprite* cardArr[4][4];
	//游戏总分
	int score;
	//定义显示分数的控件
	cocos2d::LabelTTF* labelTTFCardNumber;

};

#endif // __HELLOWORLD_SCENE_H__
