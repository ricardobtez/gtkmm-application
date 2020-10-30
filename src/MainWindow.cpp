
#include <iostream>
#include <gtkmm/menuitem.h>
#include "MainWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow(),
    m_menu(Gtk::MenuBar())
{
    // Sets the title of the window. Property of the Gtk::Window super class
    set_title(Glib::ustring("Application Title"));
    int width = 400;
    int heigth = 400;
    set_default_size(width, heigth);
    
    auto fileMenu = new Gtk::MenuItem("_File");
    fileMenu->set_visible();
    fileMenu->activate();
    //fileMenu->register_window(*static_cast<const Glib::RefPtr<Gdk::Window>>(this));
    m_menu.append(*fileMenu);
}

