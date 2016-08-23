#include <LiquidCrystal_I2C.h>

class LcdController {
  public:
    LcdController(LiquidCrystal_I2C& lcd) : _lcd(lcd) {};
    void print(String text, int lin , int col, boolean clear = false);
    void init(int col, int lin, String title, String load);
  private:
    LiquidCrystal_I2C& _lcd;
};

