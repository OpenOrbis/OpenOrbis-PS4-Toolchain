#include "ootk_ApplicationBase.hpp"

#include <iostream>

// dummy methods:
bool ootk::ApplicationBase::Init() {
    try {
        std::cout << "OpenOrbis Toolkit - Init()" << std::endl;
        // should init with a default user id.
        Input.Init();
        std::cout << "Input ok" << std::endl;
        // 720p is the 'safe' resolution on a PS4, works in 99.99% cases.
        Graphics.Init(1280, 720);
        std::cout << "Graphics ok" << std::endl;
        return true;
    } catch (const Exception& oe) {
        std::cerr << "OO Init() Exception:" << oe.What() << std::endl;
        return false;
    }
}

bool ootk::ApplicationBase::Logic() {
    Input.Logic();
    Graphics.Logic();
    Audio.Logic();
    
    /* -- your logic code goes here -- */
    return true;
}

void ootk::ApplicationBase::Render() {
    Graphics.BeginRender();
    /* -- your render code here, please don't do logic or else you'll break the universe -- */
    Graphics.EndRender();
    /* render code does not return anything, if you need to do that, signal through Logic() please :| */
}

ootk::ApplicationBase::~ApplicationBase() {
    // destructors of member classes should take care of everything...
}
