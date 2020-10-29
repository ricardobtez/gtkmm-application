
#include <iostream>
#include "MainWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow()
{
    // Sets the title of the window. Property of the Gtk::Window super class
    set_title(Glib::ustring("Application Title"));
    int width = 200;
    int heigth = 200;
    int x =0, y=0;
    set_default_size(width, heigth);
    get_position(x, y);
    std::cout << "The default size of the application is:" << std::to_string(width * heigth) << std::endl;
}

