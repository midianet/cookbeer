#include <MenuSystem.h>
class MenuController {
  public:
    void init(char* title);
    void addMenu(Menu* menu);
    Menu* getCurrent();
    void prev();
    void next();
    void select();
    void back();
  private:
    const char* _title;
    MenuSystem _mnSystem;
    const Menu _mnRoot;
};

