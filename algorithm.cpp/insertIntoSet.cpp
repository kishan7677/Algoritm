#include <set>
#include <vector>
#include <iostream>

int main()
{
    std::set<int> mySet;

    std::vector<int> vec = {1, 3,3,4,5,7,2,6};
    for(int i=0;i<vec.size();i++)
    mySet.insert(vec[i]); // Insertion involves comparison and placement

    // Printing the contents of the set
    for (const auto i : mySet)
    {
        
        
            std::cout << i << " ";
        
        
    }

    return 0;
}
