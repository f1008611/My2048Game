#include "HelloWorldScene.h"
#include "CardSprite.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }


	auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(HelloWorld::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);


	//������Ϸ�ı�����ɫ
	auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180,170,160,255));
	this->addChild(layerColorBG);

    Size visibleSize = Director::getInstance()->getVisibleSize();

		//������Ƭ
	createCardSprite(visibleSize);
    //����2���Զ����ɿ�Ƭ
	autoCreateCardNumber();
	autoCreateCardNumber();

	//���Ϸ�������Ϸ�ķ���
	//���롰������label
	auto labelTTFCardNumberName = LabelTTF::create("SCORE","HiraKakuProN-W6",40);
	labelTTFCardNumberName->setPosition(Point(visibleSize.width/3,visibleSize.height-50));
	this->addChild(labelTTFCardNumberName);

	//�������ķ���
	labelTTFCardNumber = LabelTTF::create("0","HiraKakuProN-w6",50);
	labelTTFCardNumber->setPosition(Point(visibleSize.width-400,visibleSize.height-50));
	this->addChild(labelTTFCardNumber);

	score=0;


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
		//�ж���Ϸ�Ƿ��ܼ���  
         doCheckGameOver(); 
		}
		else
		{
			//����
			doRight();
			//�ж���Ϸ�Ƿ��ܼ���  
         doCheckGameOver(); 
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
			//�ж���Ϸ�Ƿ��ܼ���  
         doCheckGameOver(); 
		}
		else
		{
			//����
			doUp();
			//�ж���Ϸ�Ƿ��ܼ���  
         doCheckGameOver(); 
		}

	}
}


//�����������ҵķ���
bool HelloWorld::doUp(){
    bool isdo = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 3; y >= 0; y--) {
            
            for (int y1 = y - 1; y1 >= 0; y1--) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        
                        y++;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x][y1]->setNumber(0);
                        //�ı���� 
                        score += cardArr[x][y]->getNumber(); 
						log("doUp");
						log(String::createWithFormat("%i",cardArr[x][y]->getNumber())->getCString());
                        labelTTFCardNumber->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
            }
            
        }
    }
    return isdo;
}

bool HelloWorld::doDown(){
    bool isdo = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            
            for (int y1 = y + 1; y1 < 4; y1++) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        
                        y--;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x][y1]->setNumber(0);
                        //�ı����  
                        score += cardArr[x][y]->getNumber();  
						log("doDown");
						log(String::createWithFormat("%i",cardArr[x][y]->getNumber())->getCString());
                        labelTTFCardNumber->setString(String::createWithFormat("%i",score)->getCString());

                        isdo = true;
                    }
                    break;
                }
            }
            
        }
    }
    return isdo;
}

bool HelloWorld::doLeft(){
    bool isdo = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            
            for (int x1 = x + 1; x1 < 4; x1++) {
                if (cardArr[x1][y]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        
                        x--;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x1][y]->setNumber(0);
                        //�ı����  
                        score += cardArr[x][y]->getNumber(); 
						log("doLeft");
						log(String::createWithFormat("%i",cardArr[x][y]->getNumber())->getCString());
                        labelTTFCardNumber->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
            }
            
        }
    }
    return isdo;
}

bool HelloWorld::doRight(){
    bool isdo = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 3; x >= 0; x--) {
            
            for (int x1 = x - 1; x1 >= 0; x1--) {
                if (cardArr[x1][y]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        
                        x++;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x1][y]->setNumber(0);
                        //�ı����  
                        score += cardArr[x][y]->getNumber(); 
						log("doRight");
						log(String::createWithFormat("%i",cardArr[x][y]->getNumber())->getCString());
                        labelTTFCardNumber->setString(String::createWithFormat("%i",score)->getCString());
                        isdo = true;
                    }
                    break;
                }
            }
            
        }
    }
    return isdo;
}



//������Ƭ
void HelloWorld::createCardSprite(cocos2d::Size size)
{
	//�����Ԫ��Ŀ�Ⱥ͸߶�
	int unitSize = (size.height-128)/4;

	//4*4�ĵ�Ԫ��
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			CardSprite* card = CardSprite::createCardSprite(0, unitSize, unitSize, unitSize*i+200, unitSize*j+20);
			addChild(card);
			//�ѿ�Ƭ���뵽������
			cardArr[i][j] = card;
		}
	}
}

//�Զ����ɿ�Ƭ
void HelloWorld::autoCreateCardNumber()
{
	int i = CCRANDOM_0_1()*4;
	int j = CCRANDOM_0_1()*4;

	//�ж��Ƿ����λ���Ѵ��ڿ�Ƭ
	if(cardArr[i][j]->getNumber() > 0){
		autoCreateCardNumber();
	}else{
		cardArr[i][j]->setNumber(CCRANDOM_0_1()*10 < 1 ? 4: 2);
	}
}

//�ж���Ϸ�Ƿ��ܼ���
void HelloWorld::doCheckGameOver(){
    bool isGameOver = true;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (cardArr[x][y]->getNumber() == 0||
                (x>0&&(cardArr[x][y]->getNumber() == cardArr[x-1][y]->getNumber()))||
                (x<3&&(cardArr[x][y]->getNumber() == cardArr[x+1][y]->getNumber()))||
                (y>0&&(cardArr[x][y]->getNumber() == cardArr[x][y-1]->getNumber()))||
                (y<3&&(cardArr[x][y]->getNumber() == cardArr[x][y+1]->getNumber()))) {
                isGameOver = false;
            }
        }
    }
    if (isGameOver) {  
        //��Ϸ���������¿�ʼ��Ϸ  
        log("��Ϸ����");  
        Director::getInstance()->replaceScene(TransitionFade::create(1, HelloWorld::createScene()));  
	}else{
	autoCreateCardNumber();
	} 
}
