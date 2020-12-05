#include <iostream>
#include <giomm/menu.h>
#include "MainApplication.hpp"
#include "MainWindow.hpp"

MainApplication::MainApplication(void) :
    Gtk::Application("gtkmm-application.com")
{
    //Glib::set_application_name("Main Menu Example");
}


Glib::RefPtr<MainApplication> MainApplication::create()
{
    return Glib::RefPtr<MainApplication>(new MainApplication());
}

void MainApplication::create_window(void)
{
    auto window = new MainWindow();
    
    // Makes sure the application runs as long as the window is open
    add_window(*window);

    // Gtk::Application::add_window() connects a signal handler to the window's
    // signal_hide(). That handler removes the window from the application.
    // If it's the last window to be removed, the application stops running.
    // Gtk::Window::set_application() does not connect a signal handler, but is
    // otherwise equivalent to Gtk::Application::add_window().

    // Delete the window when it is hidden.
    window->signal_hide().connect(sigc::bind<Gtk::Window*>(
        sigc::mem_fun(*this, &MainApplication::on_window_hide), window));

    // let's show a window.
    window->show_all();
}

void MainApplication::on_startup(void)
{
    // Call of the base class function
    Gtk::Application::on_startup();

    Glib::RefPtr<Gio::Menu> fileMenu = Gio::Menu::create();
    fileMenu->append("_New Project", "app.new");
    fileMenu->append("_Open Project", "app.open");
    fileMenu->append("_Save Project", "app.save");
    fileMenu->append("_Quit", "app.quit");


    Glib::RefPtr<Gio::Menu> menuBar = Gio::Menu::create();
    menuBar->insert_submenu(0, "_File", fileMenu);
    menuBar->append("_Edit");

    Glib::RefPtr<Gio::Menu> appMenu = Gio::Menu::create();
    appMenu->insert_submenu(0, "_File", fileMenu);

    set_accel_for_action("app.new",  "<Primary>n");
    set_accel_for_action("app.open", "<Primary>o");
    set_accel_for_action("app.save", "<Primary>s");
    set_accel_for_action("app.quit", "<Primary>q");

    // Create actions for menus and toolbars.
    // We can use add_action()because Gtk::Application derives from Gio::ActionMap
    //File|New sub menu:
    add_action("new",
        sigc::mem_fun(*this, &MainApplication::on_menu_file_new));
        
    add_action("open",
        sigc::mem_fun(*this, &MainApplication::on_menu_file_open));

    add_action("save",
        sigc::mem_fun(*this, &MainApplication::on_menu_file_save));
        
    // File menu
    add_action("quit", sigc::mem_fun(*this, &MainApplication::on_menu_file_quit));

    // Help menu
    add_action("about", sigc::mem_fun(*this, &MainApplication::on_menu_help_about));

    set_app_menu(appMenu);
    set_menubar(menuBar);
}

void MainApplication::on_activate(void)
{
    create_window();
}


void MainApplication::on_window_hide(Gtk::Window* window)
{
    delete window;
}

void MainApplication::on_menu_file_new(void)
{
    std::cout << "A File|New Item was selected\n";
}

void MainApplication::on_menu_file_open(void)
{
    std::cout << "A File|Open Item was selected\n";
}

void MainApplication::on_menu_file_save(void)
{
    std::cout << "A File|Save Item was selected\n";
}

void MainApplication::on_menu_file_quit(void)
{
    std::cout << G_STRFUNC << std::endl;
    quit();
    
    // Gio::Application::quit() will make Gio::Application::run() return,
    // but it's a crude way of ending the program. The window is not removed
    // from the application. Neither the window's nor the application's
    // destructors will be called, because there will be remaining reference
    // counts in both of them. If we want the destructors to be called, we
    // must remove the window from the application. One way of doing this
    // is to hide the window.
    std::vector<Gtk::Window*> windows = get_windows();
    if (windows.size() > 0)
        windows[0]->hide(); // In this simple case, we know there is only one window
}

void MainApplication::on_menu_help_about(void)
{
    std::cout << "App|Help|About was selected." << std::endl;
}



