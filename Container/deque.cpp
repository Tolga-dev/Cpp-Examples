#include <iostream>
#include <deque>




int main()
{
    std::deque<int> characters;

    auto print_deque = [&](){
        for (int c : characters)
            std::cout << c << ' ';
        std::cout << '\n';
        std::cout << characters.size() <<'\n';
    };

    characters.assign(5,6);
    characters.resize(70);
    print_deque();
    characters.resize(6);
    print_deque();
    characters.shrink_to_fit();
    characters.insert(characters.begin(),5, 20);
    characters.insert(std::next(characters.begin(), 2),5, 20);
    characters.erase(characters.begin(),characters.begin() + 10);
    print_deque();

    int a = 5;
    characters.push_back(a);
    print_deque();
    std::cout << a << std::endl;
    characters.push_back(std::move(a));
    characters.emplace_back(std::move(a));
    print_deque();
    std::cout << a << std::endl;


}
