#include <string>

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void display() = 0;
        virtual const std::string &getName() const = 0;
};