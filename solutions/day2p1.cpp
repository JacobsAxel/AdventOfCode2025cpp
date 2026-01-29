    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <array>
    #include <sstream>

    long long solution(std::string fileName);
    std::vector<std::array<long long, 2>> convertToArrayOfMinMaxPairs(std::string fileName);
    long long checkPair(std::array<long long, 2> pair);
    bool checkNumber(long long number);

    // This is definitely a "bruteforce" solution, but i coudn't figure out a handy math trick probably something like palindrome but it seemed harder with pairs instead of mirror
    // TODO improve later
    
    int main() 
    {
        std::cout << solution("../inputs/day2p1.txt");
    }

    long long solution(std::string fileName)
    {
        long long totalSum = 0;
        std::vector<std::array<long long, 2>> pairs = convertToArrayOfMinMaxPairs(fileName);
        for(std::array<long long, 2> pair:pairs)
        {
            totalSum+=checkPair(pair);
        }
        return totalSum;
    }

    std::vector<std::array<long long, 2>> convertToArrayOfMinMaxPairs(std::string fileName)
    {
        std::string line, seperatedString;
        std::ifstream MyReadFile(fileName);
        std::vector<std::array<long long, 2>> pairsArray;
        std::getline(MyReadFile,line);
        std::stringstream x(line);

        while (std::getline(x, seperatedString, ','))
            {
                size_t dash = seperatedString.find('-');
                long long min = std::stoll(seperatedString.substr(0, dash));
                long long max = std::stoll(seperatedString.substr(dash + 1));
                pairsArray.push_back({min,max});
            }
        return pairsArray;
    }

    long long checkPair(std::array<long long, 2> pair)
    {
        long long sum = 0;
        for(long long currentNumber = pair[0]; currentNumber<=pair[1];++currentNumber)
        {
            if(checkNumber(currentNumber))
            {
                sum+=currentNumber;
            }
        }
        return sum;
    }

    bool checkNumber(long long number)
    {
        std::string s = std::to_string(number);

        /* 
        if(s.size() % 2 == 0 && (s.substr(0,s.size()/2) == s.substr(s.size()/2)))
        {
            std::cout << number << "\n";
        }
        */

        return (s.size() % 2 != 0) ? false : (s.substr(0,s.size()/2) == s.substr(s.size()/2));
    }