
#include <iostream>
#include <gtkmm/menuitem.h>
#include <gtkmm/toolbar.h>
#include "MainWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow(),
    m_box(Gtk::ORIENTATION_VERTICAL)
{
    // Sets the title of the window. Property of the Gtk::Window super class
    set_title(Glib::ustring("Application Title"));
    int width = 400;
    int heigth = 400;
    set_default_size(width, heigth);

    add(m_box);

    add_action("copy",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    add_action("paste",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    //add_action("something",
    //    sigc::mem_fun(*this, &MainWindow::on_menu_others));
        
    // choises memus, to demonstrate Radio Items,
    // using our convenience methods for string and int radio values:
    m_refChoice = add_action_radio_string("choice",
        sigc::mem_fun(*this, &MainWindow::on_menu_choices), "a");
    m_refChoiceOther = add_action_radio_integer("choiceother",
        sigc::mem_fun(*this, &MainWindow::on_menu_choices_other), 1);
    m_refToggle = add_action_bool("sometoggle",
        sigc::mem_fun(*this, &MainWindow::on_menu_toggle), false);
        
    // Help menu
    add_action("about", sigc::mem_fun(*this, &MainWindow::on_menu_others));

    m_refBuilder = Gtk::Builder::create();

    std::string builderFilename = "../src/BuilderFiles/MainWindow.xml";

    try
    {
      m_refBuilder->add_from_file(builderFilename);
    }
    catch (const Glib::Error& ex)
    {
      std::cerr << "Building toolbar failed: " <<  ex.what();
    }
    
    Gtk::Toolbar* toolbar = nullptr;
    m_refBuilder->get_widget("toolbar", toolbar);
    if (!toolbar)
    {
        std::cerr << "The toolbar does not exist\n";
    }
    else
    {
        m_box.pack_start(*toolbar, Gtk::PACK_SHRINK);
    }
}
MainWindow::~MainWindow(void)
{

}


void MainWindow::on_menu_others()
{
    std::cout << "A menu item was selected." << std::endl;
}

void MainWindow::on_menu_choices(const Glib::ustring& parameter)
{
    //The radio action's state does not change automatically:
    m_refChoice->change_state(parameter);

    Glib::ustring message;
    if(parameter == "a")
        message = "Choice a was selected";
    else
        message = "Choice b was selected";

    std::cout << message << std::endl;
}

void MainWindow::on_menu_choices_other(const int parameter)
{
    //The radio action's state does not change automatically:
    m_refChoice->change_state(parameter);

    Glib::ustring message;
    if (parameter == 1)
        message = "Choice 1 was selected";
    else
        message = "Choice 2 was selected";

    std::cout << message << std::endl;
}

void MainWindow::on_menu_toggle(void)
{
    bool active = false;
    m_refToggle->get_state(active);

    // The toggle action's state does not change automatically
    active = !active;
    m_refToggle->change_state(active);

    Glib::ustring message;

    if (active)
        message = "Toggle is active";
    else
        message = "Toggle is inactive";

    std::cout << message << std::endl;
}





