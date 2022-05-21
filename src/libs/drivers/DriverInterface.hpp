
namespace kac
{

namespace cudalearn
{

class DriverInterface
{

public:

    DriverInterface(){};

    ~DriverInterface(){};

    void virtual Initialize() = 0;

    void virtual Execute() = 0;

    void virtual Finalize() = 0;

protected:

private:

};

}

}
