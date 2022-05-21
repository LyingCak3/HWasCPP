
#ifndef DriverInterface_hpp
#define DriverInterface_hpp

namespace kac
{

namespace cudalearn
{

class DriverInterface
{

public:

    DriverInterface(){};

    ~DriverInterface(){};

    void virtual ParseArguments( int argc, char* argv ) = 0;

    void virtual Initialize() = 0;

    void virtual Execute() = 0;

    void virtual Finalize() = 0;

protected:

private:

};

}

}

#endif
