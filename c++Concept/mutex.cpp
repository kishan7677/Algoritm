#include<bits/stdc++.h>

class Foo
{
public:
    int m_stage = 0;
    std::condition_variable cv;
    std::mutex mtx;
    Foo() : m_stage(0)
    {
    }

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]
                { return m_stage == 0; });
        printFirst();
        m_stage = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]
                { return m_stage == 1; });
        printSecond();
        m_stage = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]
                { return m_stage == 2; });
        printThird();
    }
};