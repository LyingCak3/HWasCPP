
#ifndef SimpleDriver_hpp
#define SimpleDriver_hpp

#include "DriverInterface.hpp"

namespace kac
{

namespace cudalearn
{

class SimpleDriver : public DriverInterface
{

public:

    SimpleDriver();

    ~SimpleDriver();

    void virtual ParseArguments( int argc, char** argv );

    void virtual Initialize();

    void virtual Execute();

    void virtual Finalize();

};

}

}

#endif
