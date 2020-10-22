<H1> gtmm-application </H1>
<H3> Overview</H3>
gtkmm-application is a project planned to be used as a template for projects looking to take advantage of the GTK+ GUI library with C++.

In this project, you could decide which features you will need for your application by performing the proper request to the build script, or updating these scripts.

<H3>Building the project</H3>
To build the project with the default configuration, you will only need to perform the following commands:
```bash
python build.py
```
This command will create the appropiate folder, call cmake and compile the project


<H3>Dependencies</H3>
The dependencies for the building of this project are the following:


```
gtkmm-3.0 or higher
cmake 3.15 or higher
pkgconfig
g++ or clang supporting c++17
python 3.x
```
