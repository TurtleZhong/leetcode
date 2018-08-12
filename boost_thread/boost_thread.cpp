#include <boost/thread.hpp>
#include <iostream>

using namespace std;

boost::mutex io_mutex;
struct Count
{
    Count(int id) : id(id) { }

    void operator()()
    {
        for (int i = 0; i < 10; ++i)
        {
            boost::mutex::scoped_lock
                    lock(io_mutex);
            std::cout << id << ": "
                      << i << std::endl;
        }
    }

    int id;
};

int main(int argc, char* argv[])
{
    boost::thread thrd1(Count(1));
    boost::thread thrd2(Count(2));
    thrd1.join();
    thrd2.join();
    return 0;
}