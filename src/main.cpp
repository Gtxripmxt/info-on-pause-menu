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
    auto playLayer = GameManager::sharedState()->getPlayLayer();
    if (!playLayer) {
        log::warn("PlayLayer not found!");
        return;
    }

    auto level = playLayer->m_level;
    if (!level) {
        log::warn("Level not found!");
        return;
    }

    auto infolayerthing = InfoLayer::create(level, nullptr, nullptr);

    auto ccscene = utils::get<cocos2d::CCScene>();
    if (!ccscene) {
        log::warn("CCScene not found!");
        return;
    }

    auto zOrder = ccscene->getHighestChildZ();

    ccscene->addChild(infolayerthing, zOrder + 1);
    infolayerthing->showLayer(false);
	}
};
