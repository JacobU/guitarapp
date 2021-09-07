/*
 * Launcher.cpp
 * The first file of our project.
 *
 */
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "Note.h"

using namespace std;

int main() {

	Note n1(3);
	cout << "The program launched " << "Test note " << n1 << endl;

//	*****UNCOMMENT TO TEST*********


    try {
        auto result = Catch::Session().run();
        return (result < 0xFF ? result : 0xFF);
    } catch (const exception& ex) {
        auto pMessage = ex.what();
        if (pMessage) {
            cout << "An unhandled exception was thrown:\n" << pMessage;
        }
        return -1;
    }

    return 0;


} // end main
