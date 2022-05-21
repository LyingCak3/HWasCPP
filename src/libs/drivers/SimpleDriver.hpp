
#include "DriverInterface.hpp"

namespace kac
{

namespace cudalearn
{

class SimpleDriver : DriverInterface
{

    SimpleDriver();

    ~SimpleDriver();

    void virtual Initialize();

    void virtual Execute();

    void virtual Finalize();

};

}

}
