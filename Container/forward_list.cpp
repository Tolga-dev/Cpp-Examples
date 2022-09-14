#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> cr;
    std::forward_list<int> crcp;
    auto print_forward_list = [&](){
        for (int c : cr)
            std::cout << c << ' ';
        std::cout << '\n';
        std::cout << cr.front() <<'\n';
        std::cout << cr.empty() <<'\n';

    };

    cr.assign(5, 1 );
    cr.insert_after(cr.begin(), 31);
    cr.insert_after(cr.begin(), 32);
    cr.insert_after(cr.begin(), 32);
    cr.erase_after(cr.begin());
    cr.push_front(311);
    cr.emplace_front(31211);
  //  cr.pop_front();
    //crcp = cr;
//    cr.merge(crcp);
    cr.unique();
 //   crcp.splice_after(std::next(cr.begin()), cr);

 //   cr.clear();

    print_forward_list();

}