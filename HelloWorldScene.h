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

	//�������������ʶ����¼����
    //�����¼��ص���������ʼ�ʹ�������
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
 
    //�����������ҵķ���
    bool doUp();
    bool doDown();
    bool doLeft();
    bool doRight();

		//������Ƭ
	void createCardSprite(cocos2d::Size size);
		//�Զ����ɿ�Ƭ
	void autoCreateCardNumber();

		//�ж���Ϸ�Ƿ��ܼ���
	void doCheckGameOver();
 
private:
    //���Ԫ��
    int firstX,firstY,endX,endY;
	//����һ����Ƭ��λ����
	CardSprite* cardArr[4][4];
	//��Ϸ�ܷ�
	int score;
	//������ʾ�����Ŀؼ�
	cocos2d::LabelTTF* labelTTFCardNumber;

};

#endif // __HELLOWORLD_SCENE_H__
