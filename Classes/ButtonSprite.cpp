#include "ButtonSprite.h"

ButtonSprite::ButtonSprite()
{
}
ButtonSprite::~ButtonSprite()
{
}

ButtonSprite* ButtonSprite::createWithButtonType(kButton buttonType) {
	ButtonSprite *pRet = new ButtonSprite();
	if(pRet && pRet->initWithButtonType(buttonType)) {
		pRet->autorelease();
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool ButtonSprite::initWithButtonType(kButton buttonType) {
	if(!CCSprite::initWithFile(getButtonImageFileName(buttonType))) {
		return false;
	}
	m_buttonType = buttonType;
	return true;
}

const char* ButtonSprite::getButtonImageFileName(kButton buttonType) {
	switch(buttonType) {

	case kb1:
		return "b1.png";
	case kb2:
		return "b2.png";
	case kb3:
		return "b3.png";
	case kb4:
		return "b4.png";
	case kb5:
		return "b5.png";
	case kb6:
		return "b6.png";
	case kb7:
		return "b7.png";
	case kb8:
		return "b8.png";
	default:
		CCAssert(false, "invalid buttonType");
		return "";
	}
}
