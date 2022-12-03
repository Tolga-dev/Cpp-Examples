#include <cassert>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string_view>
#include <system_error>
#include <vector>
#include <tuple>
#include <string>

using namespace std;
std::vector<std::string> splitString(const std::string& str)
{
    std::vector<std::string> tokens;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        tokens.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    tokens.push_back(str.substr(prev));

    return tokens;

}

int main()
{

}




void day3()
{
    std::vector<std::string> input = {""};
    std::vector<std::string> newInput = {""};
    std::vector<std::string> Chars = {""};
    input = splitString(input[0]);


    /*
    for(auto&k : input)
    {
        std::string b = k.substr(0,k.length()/2);
        std::string c = k.substr(k.length()/2,k.length());
        std::string m = "";
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        for(int i = 0; i < b.length(); i++)
        {
            for(int j = 0; j < c.length(); j++)
            {
                if(b[i] == c[j])
                {
                    m = b[i];
                    Chars.push_back(m);
                    break;
                }
            }
            if(b[i] == m[0])
                break;

        }
    }
     */

    for(int i =0; i < input.size(); i +=3 )
    {
        std::cout << input[i] << std::endl;
        std::cout << input[i+1] << std::endl;
        std::cout << input[i+2] << std::endl;
        std::string temp = "";
        for(int k = 0 ; k < input[i].length() ; k++)
        {
            for(int l = 0 ; l < input[i+1].length() ; l++)
                if(input[i][k] == input[i+1][l])
                    for(int n = 0 ; n < input[i+2].length() ; n++)
                    {
                        if(temp[0] == input[i][k])
                            break;
                        if(input[i][k] == input[i+2][n])
                        {
                            temp = input[i][k];
                            Chars.push_back(temp);
                            break;
                        }
                    }

            if(temp[0] == input[i][k])
                break;
            if(temp[0] == input[i][k])
                break;

        }
    }


    int sum = 0;
    for(auto &a : Chars)
    {
        if(a[0] != 0)
        {
            std::cout << (int)a[0]<< std::endl;

            if(islower(a[0]))
                sum += (int)a[0]-96;
            else
                sum += (int)a[0]-(65-27);
        }

    }

    std::cout << sum << std::endl;

}
void day2()
{
    int score = 0;
    std::vector<std::string> input = {""};
    input = splitString(input[0]);
    input.push_back("q");
    std::string temp;

    for (int i = 0; i < input.size()*3; ++i) {
        if(input[i][2] == 'X')
        {
            if(input[i][0] == 'C')
                input[i][2] = 'Y';
            if(input[i][0] == 'A')
                input[i][2] = 'Z';
        }
        else if(input[i][2] == 'Y')
        {
            if(input[i][0] == 'A')
                input[i][2] = 'X';
            if(input[i][0] == 'C')
                input[i][2] = 'Z';
        }
        else if(input[i][2] == 'Z')
        {
            if(input[i][0] == 'C')
                input[i][2] = 'X';
            if(input[i][0] == 'A')
                input[i][2] = 'Y';
        }

        if(input[i][2] == 'X'){

            score += 1;

            temp = input[i][0];
            if(temp == "A"){
                score += 3;
            }
            else if(temp == "B")
            {
                score += 0;
            }
            else{
                score += 6;
            }
            std::cout << "x" << score << std::endl;

        }

        if(input[i][2] == 'Y'){

            score += 2;

            temp = input[i][0];
            if(temp == "A"){
                score += 6;
            }
            else if(temp == "B")
            {
                score += 3;
            }
            else{
                score += 0;
            }
            std::cout << "y" << score << std::endl;

        }
        if(input[i][2] == 'Z'){

            score += 3;

            temp = input[i][0];
            if(temp == "A"){
                score += 0;
            }
            else if(temp == "B")
            {
                score += 6;
            }
            else{
                score += 3;
            }
            std::cout << "z" << score << std::endl;

        }
        std::cout <<input[i] << std::endl;

        if(input[i][0] == 'q')
            break;
    }
    std::cout << score << std::endl;


}
void day1()
{
    std::vector<std::string> newInput;
    std::vector<int> newIntInput;
    std::vector<int> newSums;
    std::vector<std::string> input = {""};

    newInput = splitString(input[0]);

    for (auto const &token: newInput) {
        int value = 0;
        std::string_view k = token;
        std::from_chars(k.begin(), k.end(), value);
        if(token.size() == 0)
            newIntInput.push_back(-1);
        newIntInput.push_back(value);
    }

    newIntInput.push_back(-1);
    int big = 0;
    for(auto const &t : newIntInput)
    {

        if(t == -1)
        {
            newSums.push_back(big);
            big = 0;
            continue;
        }
        big += t;

    }
    sort(newSums.rbegin(), newSums.rend());

    for(auto &k : newSums)
    {
        std::cout << k <<std::endl;
    }


    int sum =0;
    int count = 0;
    for(auto &k : newSums)
    {
        if(count == 3)
            break;
        sum += k;
    }
    std::cout << sum << std::endl;

/*
    int newBig = 0;
    int temp = 0;
    for(auto const &t : newSums)
    {
        if(newBig < t)
            newBig = t;

    }

    std::cout << newBig << std::endl;
*/
}