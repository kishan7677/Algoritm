#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

counting_semaphore<3> db_semaphore(3); // Allow max 3 concurrent DB users

void accessDatabase(int clientId)
{
    std::cout << "Client " << clientId << " is trying to access DB.\n";

    db_semaphore.acquire(); // Wait if 3 clients are already using it

    std::cout << "Client " << clientId << " has started DB operation.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate DB work
    std::cout << "Client " << clientId << " has finished DB operation.\n";

    db_semaphore.release(); // Free up access for others
}

int main()
{
    std::vector<std::thread> clients;
    for (int i = 1; i <= 8; ++i)
    {
        clients.emplace_back(accessDatabase, i);
    }

    for (auto &t : clients)
    {
        t.join();
    }
}
