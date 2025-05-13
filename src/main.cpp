#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/InfoLayer.hpp>
class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();

		auto infoButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
			this,
			menu_selector(MyPauseLayer::onInfoButton)
		);

		auto menu = this->getChildByID("center-button-menu");
		if (!menu) {
			log::warn("center-button-menu not found!");
			return;
		}
                infoButton->setScale(1.2f);
			
		infoButton->setID("info-button"_spr);
		menu->addChild(infoButton);

		menu->updateLayout();
	}

	void onInfoButton(CCObject*) {
                auto infolayerthing = InfoLayer::create())
                auto ccscene = utils::get<cocos2d::CCScene>();
                auto zOrder = ccscene->getHighestChildZ();
                scene->addChild(infolayerthing, zOrder + 1);
                infolayerthing->showLayer(false);
	}
};
