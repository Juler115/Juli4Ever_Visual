#include "Juli4Ever.h"
#include <ui/UITextField.h>

USING_NS_CC;

Scene* BienvenidaS::createScene()
{
    return BienvenidaS::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Bienvenida.cpp\n");
}


bool BienvenidaS::init()
{
    if (check())
    {
        if (!Scene::init())
        {
            return false;
        }
        Music("Ohayou Sayori!");
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();


        auto back = Sprite::create("Utils/daylight_Background.png");
        back->setScale(1.3);
        back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(back, 0);

        _Voz = Label::createWithTTF("Hello World", "fonts/ComicRelief.ttf", 12);
        _Voz->setString(Bienvenida());
        _Voz->enableGlow(Color4B::BLACK);
        _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
        this->addChild(_Voz, 8);
        _TextBox = Sprite::create("Utils/blueStextbox.png");
        _TextBox->setScale(1.2);
        _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
        this->addChild(_TextBox, 7);

        if (Juli.Afecto() < -1) {
            _l = Sprite::create("Juli_sprites/Poses/2l.png");
            _l->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_l, 3);
            _r = Sprite::create("Juli_sprites/Poses/2r.png");
            _r->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_r, 4);
            _c = Sprite::create("Juli_sprites/Cabezas/Molesta.png");
            _c->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30 - .15));
            this->addChild(_c, 5);
        }
        else {
            _l = Sprite::create("Juli_sprites/Poses/1l.png");
            _l->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_l, 3);
            _r = Sprite::create("Juli_sprites/Poses/1r.png");
            _r->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_r, 4);
            _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
            _c->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30 - .15));
            this->addChild(_c, 5);
        }


        auto listener = EventListenerKeyboard::create();
        listener->onKeyPressed = CC_CALLBACK_2(BienvenidaS::Op, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }
    else
    {
        if (!Scene::init())
        {
            return false;
        }
        Music("Ohayou Sayori!");
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();


        auto back = Sprite::create("Utils/daylight_Background.png");
        back->setScale(1.3);
        back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(back, 0);

        _Voz = Label::createWithTTF("Hola mi nombre es Juli,\n y estoy aqui para divertirnos un rato\n cual es tu nombre ?", "fonts/ComicRelief.ttf", 12);
        _Voz->enableGlow(Color4B::BLACK);
        _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
        this->addChild(_Voz, 8);
        _TextBox = Sprite::create("Utils/blueStextbox.png");
        _TextBox->setScale(1.3);
        _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
        this->addChild(_TextBox, 7);

        if (Juli.Afecto() < -1) {
            _l = Sprite::create("Juli_sprites/Poses/2l.png");
            _l->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_l, 3);
            _r = Sprite::create("Juli_sprites/Poses/2r.png");
            _r->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_r, 4);
            _c = Sprite::create("Juli_sprites/Cabezas/Molesta.png");
            _c->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30 - .15));
            this->addChild(_c, 5);
        }
        else {
            _l = Sprite::create("Juli_sprites/Poses/1l.png");
            _l->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_l, 3);
            _r = Sprite::create("Juli_sprites/Poses/1r.png");
            _r->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
            this->addChild(_r, 4);
            _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
            _c->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30 - .15));
            this->addChild(_c, 5);
            auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
            Input->setPosition(Vec2(100, 200));
            Input->setColor(Color3B(0, 255, 255));
            this->addChild(Input, 10);
            auto ST2 = EventListenerKeyboard::create();
            ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                {
                    if (Datos["Cumple"] == "") {
                        string nombre = Input->getString();
                        ofstream data;
                        data.open("Data.txt", ios::app);
                        data << "\nNombre " << nombre;
                        data.close();
                    }
                    _Voz->setString("Hola es un gusto conocerte");
                    _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");

                    auto Return = EventListenerKeyboard::create();
                    Return->onKeyPressed = CC_CALLBACK_2(BienvenidaS::Op, this);
                    _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
                }
            };
            _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
        }
    }
    return true;
}
    

void BienvenidaS::Op(EventKeyboard::KeyCode keyCode, Event* event)
{
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}


