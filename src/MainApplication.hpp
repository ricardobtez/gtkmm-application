#ifndef MAIN_APPLICATION_Hsa
#define MAIN_APPLICATION_H

#include <gtkmm.h>


class MainApplication : public Gtk::Application
{
public:
    static Glib::RefPtr<MainApplication> create();
protected:
    explicit MainApplication(void);
    // override default signal handlers
    void on_startup() override;
    void on_activate(void) override;

private:
    void create_window(void);

    void on_window_hide(Gtk::Window* window);
    void on_menu_file_new();
    void on_menu_file_open();
    void on_menu_file_save();
    void on_menu_file_quit();
    void on_menu_help_about();

    Glib::RefPtr<Gtk::Builder> m_refBuilder;
};

#endif /* MAIN_APPLICATION_H */

