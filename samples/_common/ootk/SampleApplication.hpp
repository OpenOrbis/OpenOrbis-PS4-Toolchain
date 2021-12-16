#pragma once

#include "ootk_ApplicationBase.hpp"


namespace nik {
    class SampleApplication : public ootk::ApplicationBase {
    public:
        virtual bool Init() override;
        virtual bool Logic() override;
        virtual void Render() override;
        virtual ~SampleApplication() override;
    };
}
