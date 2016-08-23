#include <LiquidCrystal_I2C.h>
#include "LcdController.h"
#include "TimerController.h"
//#include "MenuController.h"
#include <Thread.h>
#include <ThreadController.h>
#include <MenuSystem.h>

LiquidCrystal_I2C lcd(0x27, 2, 4, 0, 4, 5, 6, 7, 3, POSITIVE);

/*
 * Definindo os controladores
 */
LcdController    lcdController(lcd);
TimerController  timerController(0x68);
//MenuController   menuController();
ThreadController threadController();



//##################### temporario ##################################

//##################################################################

void setup() {
  //Serial.begin(9600);
  timerController.setDate(0, 44, 12, 6, 6, 8, 16);
  lcdController.init(20, 4, "CookBeer V1.0", "Carregando");
  //lcdController.write(timerController.getDate(),0,0);
  //lcdController.write(timerController.getDayOfWeek(),0,2);

  //pinMode(8,INPUT_PULLUP);
  //pinMode(9,INPUT_PULLUP);
  //pinMode(10,INPUT_PULLUP);
  //pinMode(11,INPUT_PULLUP);
  //menuController.init();
  configMenu();
  
}

void loop() {
  //lcdController.write(timerController.getTime(),0,1);

//if (digitalRead(8) == LOW) { // Botão Pressionado;
//
//  }
//if (digitalRead(9) == LOW) { // Botão Pressionado;
//    menuController.prev();
//        Serial.println("prev");
//        displayMenu();
//        delay(500);
//  }
//
//if (digitalRead(10) == LOW) { // Botão Pressionado;
//    menuController.next();
//        Serial.println("next");
//        displayMenu();
//        delay(500);
//  }
//if (digitalRead(11) == LOW) { // Botão Pressionado;
//    menuD.select();
//  }

 
}

//void execMenu(){
  
//}

void configMenu(){
      Serial.print("Entrando");
Menu menuA("LED ->");
MenuItem mnItemA1("  <-Liga");
MenuItem mnItemA2("  <-Desliga");
Menu menuB("Temperatura ->");
MenuItem mnItemB1("  <-Mínimo A");
MenuItem mnItemB2("  <-Mínomo B");
Menu menuC("Relógio ->");
MenuItem mnItemC1("  <-Mostrar");
MenuItem mnItemC2("  <-Set");
Menu menuD("Motor ->");
MenuItem mnItemD1("  <-Ativar");
MenuItem mnItemD2("  <-Desativar");

//  menuController.addMenu(&menuA);
//  menuA.add_item(&mnItemA1, &execMenu);
//  menuA.add_item(&mnItemA2, &execMenu);
//
//  menuController.addMenu(&menuB);
//  menuB.add_item(&mnItemB1, &execMenu);
//  menuB.add_item(&mnItemB2, &execMenu);
//
//  menuController.addMenu(&menuC);
//  menuC.add_item(&mnItemC1, &execMenu);
//  menuC.add_item(&mnItemC2, &execMenu);
//
//  menuController.addMenu(&menuD);
//  menuD.add_item(&mnItemD1, &execMenu);
//  menuD.add_item(&mnItemD2, &execMenu);
  
  displayMenu();
}

void displayMenu() {

//  Menu* cp_menu = menuController.getCurrent();
//  lcdController.write(cp_menu->get_name(),0,0,true);
//  lcdController.write(cp_menu->get_selected()->get_name(),0,1);
}
