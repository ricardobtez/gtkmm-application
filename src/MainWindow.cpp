
#include "MainWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow()
{
    m_childClass = new BaseClass();
    m_childClass->calculate();
}

