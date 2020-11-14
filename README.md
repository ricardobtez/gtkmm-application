![CMake-release](https://github.com/ricardobtez/gtkmm-application/workflows/CMake-release/badge.svg?branch=main&event=push)
![CMake-debug](https://github.com/ricardobtez/gtkmm-application/workflows/CMake-debug/badge.svg?branch=main&event=push)

<H1> gtmm-application </H1>
<H3> Overview</H3>
gtkmm-application is a project planned to be used as a template for projects looking to take advantage of the GTK+ GUI library with C++.

In this project, you could decide which features you will need for your application by performing the proper request to the build script, or updating these scripts.

<H3>Building the project</H3>
To build the project with the default configuration, you will only need to perform the following commands:


```bash
python build.py -b release -f
```
This command will create the appropiate folder, call cmake and compile the project with release mode and force a rebuild if the folder was compiled before


```bash
python build.py -b debug
```
This command will perform as before, except that it will compile as debug and will recompile only if needed.

If you want to know how to use the python script, you can call the following command.


```bash
python build.py -h
```

<H3>Dependencies</H3>
The dependencies for the building of this project are the following:


```
gtkmm-3.0 or higher
cmake 3.15 or higher
pkgconfig
g++ or clang supporting c++17
python 3.x
```
