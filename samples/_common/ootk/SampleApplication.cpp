#include "SampleApplication.hpp"

bool nik::SampleApplication::Init() {
    if (!ootk::ApplicationBase::Init()) return false;

    /* -- your custom initialization here -- */
}

bool nik::SampleApplication::Logic() {
    if (!ootk::ApplicationBase::Logic()) return false;

    /* -- your custom update code here -- */
}

void nik::SampleApplication::Render() {
    Graphics.BeginRender();

    /* -- your custom graphics code here -- */

    Graphics.EndRender();
}

nik::SampleApplication::~SampleApplication() {
    /* -- destructor of ApplicationBase will be called automatically -- */
    
    /* -- your dtor code here -- */
}
