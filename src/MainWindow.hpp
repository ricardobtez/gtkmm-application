#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/builder.h>


class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow(void);
    virtual ~MainWindow();
protected:
    // Signal handlers
    void on_menu_others(void);
    void on_menu_choices(const Glib::ustring& parameter);
    void on_menu_choices_other(const int parameter);
    void on_menu_toggle();

    // Child widgets
    Gtk::Box m_box;

    Glib::RefPtr<Gtk::Builder> m_refBuilder;

    //Two sets of choices:
    Glib::RefPtr<Gio::SimpleAction> m_refChoice;
    Glib::RefPtr<Gio::SimpleAction> m_refChoiceOther;

    Glib::RefPtr<Gio::SimpleAction> m_refToggle;
};

#endif /* MAIN_WINDOW_H */

