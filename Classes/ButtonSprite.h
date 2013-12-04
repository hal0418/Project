#ifndef __BUTTONSPRITE__H__
#define __BUTTONSPRITE__H__

#include "cocos2d.h"
#include "Config.h"

class ButtonSprite : public cocos2d::CCSprite {
protected:
	const char* getButtonImageFileName(kButton buttonType);
public:
	CC_SYNTHESIZE_READONLY(kButton, m_buttonType, ButtonType);

	ButtonSprite();
	virtual ~ButtonSprite();
	virtual bool initWithButtonType(kButton buttonType);
	static ButtonSprite* createWithButtonType(kButton buttonType);
};

#endif // __BUTTONSPRITE__H__
