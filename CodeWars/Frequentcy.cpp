/*
https://www.codewars.com/kata/5a8d2bf60025e9163c0000bc/train/cpp
template<typename Q>
void print_queue(std::string_view name, Q q)
{
    // NB: q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    for (std::cout << name << ": \t"; !q.empty(); q.pop())
        std::cout << q.top() << ' ';
    std::cout << '\n';
    const auto data = {1,2,3,0,5,0,1,6,8,8,6,9,1};

    unordered_map<int,int> uom_ii;
    vector<int> out;

    for (auto i : data) {
        uom_ii[i]++;
    }

    vector<pair<int,vector<int>>> el;

    for (auto i : uom_ii) {
        vector<int> temp;
        for (int j = 0; j < i.second; ++j) {
            temp.emplace_back(i.first);
        }
        el.emplace_back(i.second,temp);

    }

    sort(el.rbegin(), el.rend());


    for (const auto& i: el) {
        for (auto k : i.second) {
            out.emplace_back(k);
        }
    }

    for (auto s: out) {
        cout << s << " ";
    }

}*/
