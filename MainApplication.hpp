#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include <gtkmm.h>

class MainWindow;

class MainApplication : public Gtk::Application
{
public:
    static Glib::RefPtr<MainApplication> create();
protected:
    explicit MainApplication(void);
    // override default signal handlers
    void on_activate(void) override;
    void on_open(const Gio::Application::type_vec_files& files,
        const Glib::ustring& hint) override;

private:
    MainWindow* create_window(void);
    void on_hide_window(Gtk::Window* window);
};

#endif /* MAIN_APPLICATION_H */

