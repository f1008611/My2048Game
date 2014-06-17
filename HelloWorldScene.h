#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "cocos2d.h"


class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    

    
    // implement the "static create()" method manually
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

    private:  
      //点击元素  
      int firstX,firstY,endX,endY; 


};

#endif // __HELLOWORLD_SCENE_H__
