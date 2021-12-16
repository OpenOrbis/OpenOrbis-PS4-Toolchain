#include "SampleApplication.hpp"

int main() {
    static nik::SampleApplication app{};

    if (!app.Init()) {
        return -1;
    }

    while (app.Logic()) {
        app.Render();
    }

    return 0;
}
