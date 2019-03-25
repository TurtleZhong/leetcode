//
// Created by m on 8/11/18.
//

#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <time.h>
#include <queue>

using namespace std;


int tf = -1;
int reloc_pose = -10;

queue<int> reloc_queue;
queue<int> tfs;
boost::mutex tf_mutex;
boost::mutex reloc_mutex;
boost::condition cond;
bool fusion_system_start = false;
void odom_tf() //20hz
{
    while(true)
    {

        ++tf;
        boost::unique_lock<boost::mutex> lock_tf(tf_mutex);
        tfs.push(tf);
        cout << "odom_thread: tf = " << tf << endl;
        lock_tf.unlock();
        usleep(20000);
    }
}

void reloc()//1hz
{
    while (true)
    {

        reloc_pose+=10;
        fusion_system_start=true;
        boost::unique_lock<boost::mutex> lock_re(reloc_mutex);
        reloc_queue.push(reloc_pose);
        cout << "reloc_thread: pose = " << reloc_pose << endl;
        lock_re.unlock();
        sleep(1);
    }
}

void fusion()//10hz
{
    while (true)
    {
        boost::unique_lock<boost::mutex> lock_tf(tf_mutex);
        boost::unique_lock<boost::mutex> lock_re(reloc_mutex);

        if(fusion_system_start)
        {
            if(!reloc_queue.empty())
            {
                auto reloc = reloc_queue.back();
                reloc_queue.pop();
                lock_re.unlock();
                while (!tfs.empty())
                {
                    tfs.pop();
                }
                cout << "fusion_thread:pose = reloc_pose = " << reloc << endl;
                lock_tf.unlock();
            }
            else
            {
                cout << "fusion_thread:pose = odom_pose" << endl;
                cout << "odom.size = " << tfs.size() << endl;
                //do something
                lock_tf.unlock();
                lock_re.unlock();
            }
        }


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