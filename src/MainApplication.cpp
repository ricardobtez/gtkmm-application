
#include "MainApplication.hpp"
#include "MainWindow.hpp"

MainApplication::MainApplication(void) :
    Gtk::Application("Ricardo Benitez test Application", Gio::APPLICATION_HANDLES_OPEN)
{
}


Glib::RefPtr<MainApplication> MainApplication::create()
{
    return Glib::RefPtr<MainApplication>(new MainApplication());
}

MainWindow* MainApplication::create_window(void)
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
        sigc::mem_fun(*this, &MainApplication::on_hide_window),
        window));

    return window;
}

void MainApplication::on_activate()
{
  // The application has been started, so let's show a window.
  auto appwindow = create_window();
  appwindow->present();
}

void MainApplication::on_open(const Gio::Application::type_vec_files& files,
        const Glib::ustring& hint)
{
}

void MainApplication::on_hide_window(Gtk::Window* window)
{
    delete window;
}

