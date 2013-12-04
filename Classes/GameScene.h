#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "Config.h"

#define MAX_BUTTON 8

#define PNG_BACKGROUND "background.png"
#define PATH "/Users/hal/cocos2d-x-2.2.1/projects/Project/Resources/asdf.csv"

class GameScene : public cocos2d::CCLayer
{

protected:
	enum kTag
	{
		kTagBackground = 1,
		kTagBaseButton = 11,
	};

	enum kZOrder
	{
		kZOrderBackground,
		kZOrderButton,
		kZOrderTime
	};

	cocos2d::CCSprite* m_background;
	void showBackground();

	float m_buttonSize;
	void getButtonSize();
	void showButton();
	cocos2d::CCPoint setButton(int i);
	int getTag(int i);

	void getTouchButtonTag(cocos2d::CCPoint touchPoint, int &tag, kButton &buttonType);

	float mTime;
	cocos2d::CCLabelTTF* mTimeLabel;
	void setTime();
	void timer(float delta);

	void loadCsv();

public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameScene);

    virtual bool ccTouchBegin(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
};

#endif // __GAMESCENE_H__#endif // __GAMESCENE_H__
