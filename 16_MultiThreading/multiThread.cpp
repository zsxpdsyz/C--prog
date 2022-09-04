#include<thread>
#include<iostream>
#include<vector>
#include<mutex>

using std::cout;    using std::endl;
using std::string;  using std::vector;

void greet(int id) {
    cout << "Hello here! My name is " << id << endl;
}

int main() {
    cout << "Greetings from my threading..." << endl;

    std::thread thread1(greet, 1);
    std::thread thread2(greet, 2);

    // 阻塞主线程，直到两个线程执行完毕，如果不等待则后面的语句会先执行
    thread2.join();
    thread1.join();

    cout << "All greetings done!" << endl;

    return 0;
}