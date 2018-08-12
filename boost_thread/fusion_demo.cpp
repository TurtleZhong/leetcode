//
// Created by m on 8/11/18.
//

#include <iostream>
#include <boost/thread.hpp>
#include <time.h>
#include <queue>

using namespace std;


int tf = -1;
int reloc_pose = -10;
void odom_tf()
{
    while(true)
    {
        ++tf;
        cout << "odom_thread: tf = " << tf << endl;

        usleep(50000);
    }
}

void reloc()
{
    while (true)
    {
        reloc_pose+=10;
        cout << "reloc_thread: pose = " << reloc_pose << endl;
        sleep(1);
    }
}

void fusion()
{
    while (true)
    {
        cout << "fusion_thread:pose = " << reloc_pose << " " << tf << endl;
        usleep(100000);
    }
}

int main()
{
    boost::thread odom_tf_thread(odom_tf);
    boost::thread reloc_tf_thread(reloc);
    boost::thread fusion_thread(fusion);
    odom_tf_thread.join();
    reloc_tf_thread.join();
    fusion_thread.join();

    return 0;
}