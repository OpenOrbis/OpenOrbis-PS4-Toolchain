#ifndef _APPLICATIONBASE_HPP_
#define _APPLICATIONBASE_HPP_ 1

namespace ooexamples {
    class ApplicationBase {
    private:
    // fields:

        // handles contexts ids etc go here...

    // methods:
    
        // private methods go here...

    public:

        // Initializes the app, must be called after all constructors of all static objects are initialized (e.g. somewhere in main)
        // Returns false if failed to initialize.
        virtual bool Init() = 0;
        // Updates the logic of the app
        // Returns false if should break out of the application loop
        virtual bool Logic() = 0;
        // Renders the app
        // Must be called in the application loop, shouldn't return anything
        // (if you want to signal a quit, please do so from the Logic function!)
        virtual void Render() = 0;
        // Finishes the app, called implicitly by the compiler.
        virtual ~ApplicationBase() = 0;
        
    };
} // namespace ooexamples

#endif /* _APPLICATIONBASE_HPP_ */
