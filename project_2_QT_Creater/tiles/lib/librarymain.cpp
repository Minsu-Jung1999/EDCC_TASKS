/*
 * File: librarymain.cpp
 * ---------------------
 * This file contains a 'libraryMain' function definition that initializes the
 * SGL C++ library, then runs the student's main function in its own thread.
 * This is necessary for the Qt version of the library to function properly.
 */

#include "ginit.h"
#include "qtgui.h"

// student implements what looks like ordinary main() function, but
// will be renamed to studentMain() during build
int studentMain();
int main();
// initializes the Qt GUI library subsystems and Qt graphical console as needed
// before calling studentMain

int libraryMain(int argc, char** argv) {
    sgl::initializeLibrary(argc, argv);
#ifdef SGL_HEADLESS_MODE
    main();
#else
    ::sgl::QtGui::instance()->startBackgroundEventLoop(main);
#endif
    sgl::shutdownLibrary();
    return 0;
}
