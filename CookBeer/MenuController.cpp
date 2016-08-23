#include <MenuSystem.h>
#include "MenuController.h"

void MenuController::init(char* title){
  this->_mnSystem = MenuSystem();
  this->_mnRoot = Menu("");
  Serial.println(_title);
  _mnSystem.set_root_menu(&_mnRoot);
}

void MenuController::prev(){
  _mnSystem.prev();  
}

void MenuController::next(){
  _mnSystem.next();
}

void MenuController::select(){
  _mnSystem.select();
}

void MenuController::back(){
  _mnSystem.back();
}

Menu* MenuController::getCurrent(){
  return _mnSystem.get_current_menu();
}

void MenuController::addMenu(Menu* menu){
    Serial.println("Merda");
  _mnRoot->add_menu(menu);
}

