#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/menubar.h>

class MainWindow : public Gtk::ApplicationWindow
{
public:
    explicit MainWindow(void);
private:
    Gtk::MenuBar m_menu;
};

#endif /* MAIN_WINDOW_H */

