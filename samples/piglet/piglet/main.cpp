/* OpenOrbis Piglet app example.
 */

#include "PigletApplication.hpp"

int main() {
    static nik::PigletApplication& AppRef{ nik::GetPigletApplication() };

    // the shutdown of the app is handled in a destructor so no Quit() methods etc

	if (!AppRef.Init()) {
        // the class will print the error message to std::cerr.
        return EXIT_FAILURE;
    }
	
    while (AppRef.Logic()) {
        // only if logic update was successful, render the app:
        AppRef.Render();
    }

    return EXIT_SUCCESS;
}
