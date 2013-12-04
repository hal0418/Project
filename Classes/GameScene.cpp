#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "ButtonSprite.h"
#include "AppMacros.h"

#include <fstream>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

// èâä˙âª
bool GameScene::init()
{
    if (!CCLayer::init())
    {
        return false;
    }

    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);

    getButtonSize();
    showBackground();
    showButton();

    setTime();

    loadCsv();

    return true;
}

void GameScene::showBackground()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    // îwåiÇê∂ê¨
    m_background = CCSprite::create(PNG_BACKGROUND);
    m_background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    addChild(m_background, kZOrderBackground, kTagBackground);
}

void GameScene::getButtonSize() {
	ButtonSprite* pButton = ButtonSprite::createWithButtonType(kb1);
	m_buttonSize = pButton->getContentSize().height;
}

CCPoint GameScene::setButton(int i) {
	float setX, setY;
	float halfX = m_background->getContentSize().width / 2;
	float halfY = m_background->getContentSize().height / 2;
	float offset = m_background->getContentSize().height / 4;

	switch(i) {
	//ç∂è„(0,0)ïaÇÃ„©
	case 4:
		setX = halfX;
		setY = offset;
	break;
	case 3:
		setX = halfX + offset*3/4;
		setY = halfY - offset*3/4;
	break;
	case 2:
		setX = halfX + offset;
		setY = halfY;
	break;
	case 1:
		setX = halfX + offset*3/4;
		setY = halfY + offset*3/4;
	break;
	case 0:
		setX = halfX;
		setY = offset*3;
	break;
	case 7:
		setX = halfX - offset*3/4;
		setY = halfY + offset*3/4;
	break;
	case 6:
		setX = halfX - offset;
		setY = halfY;
	break;
	case 5:
		setX = halfX - offset*3/4;
		setY = halfY - offset*3/4;
	break;
	}
	return CCPoint(setX, setY);
}

int GameScene::getTag(int i) {
	//CCLog("%d",kTagBaseButton + i);
	return kTagBaseButton + i;
}

void GameScene::showButton() {
	for(int i=0; i<MAX_BUTTON; i++) {
		kButton buttonType = (kButton)i;
		int tag = getTag(i);
		ButtonSprite* pButton = ButtonSprite::createWithButtonType(buttonType);
		pButton->setPosition(setButton(i));
		m_background->addChild(pButton, kZOrderButton, tag);
	}
}

bool GameScene::ccTouchBegin(CCTouch* pTouch, CCEvent* pEvent) {
	return true;
}

void GameScene::getTouchButtonTag(CCPoint touchPoint, int &tag, kButton &buttonType) {
	for(int i=0; i<MAX_BUTTON; i++) {
		int currentTag = getTag(i);
		CCNode* node = m_background->getChildByTag(currentTag);
		if(node->boundingBox().containsPoint(touchPoint)) {
			tag = currentTag;
			buttonType = ((ButtonSprite*)node)->getButtonType();
			return;
		}
	}
}

void GameScene::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
	CCPoint touchPoint = m_background->convertTouchToNodeSpace(pTouch);
	int tag = 0;
	kButton buttonType;
	getTouchButtonTag(touchPoint, tag, buttonType);

	switch(tag) {
		case 11: CCLog("b1"); schedule(schedule_selector(GameScene::timer)); break;
		case 12: CCLog("b2"); unschedule(schedule_selector(GameScene::timer)); break;
		case 13: CCLog("b3"); mTime = 0; break;
		case 14: CCLog("b4"); break;
		case 15: CCLog("b5"); break;
		case 16: CCLog("b6"); break;
		case 17: CCLog("b7"); break;
		case 18: CCLog("b8"); break;

		case 0 : CCLog("background"); break;
		default: CCLog("%d",tag); break;
	}
}

void GameScene::setTime() {
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	mTimeLabel = CCLabelTTF::create("0.00s", "", TIME_FONT_SIZE);
	mTimeLabel->setPosition(ccp(winSize.width/2, winSize.height/2));
	mTimeLabel->setColor(ccc3(128,128,128));
	this->addChild(mTimeLabel, kZOrderTime);
}

void GameScene::timer(float delta) {
	mTime += delta;
	CCString* string = CCString::createWithFormat("%.2fs", mTime);
	mTimeLabel->setString(string->getCString());
}

void GameScene::loadCsv() {
	ifstream ifs(PATH);
	if(!ifs) {
		CCLog(PATH);
	}
	else{
		CCLog("!!!");
	}
}
