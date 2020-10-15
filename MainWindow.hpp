#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "ChildClass.hpp"

class MainWindow : public Gtk::ApplicationWindow
{
public:
    explicit MainWindow(void);
private:
    BaseClass* m_childClass;
};

#endif /* MAIN_WINDOW_H */

