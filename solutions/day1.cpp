    #include <iostream>
    #include <fstream>
    #include <string>

    int solution(std::string fileName);
    int rotateLeft(int start, int rotation);
    int rotateRight(int start, int rotation);

    int main() 
    {
        std::cout << solution("../inputs/day1p1.txt");
    }

    int solution(std::string fileName)
    {
        int result = 0;
        int index = 50;
        std::string line;
        std::ifstream MyReadFile(fileName);
        
        while(std::getline(MyReadFile,line))
        {
            int lineResult = (line[0]=='L') ? rotateLeft(index,std::stoi(line.substr(1))) : rotateRight(index,stoi(line.substr(1)));
            index = lineResult;
            if(lineResult==0){result+=1;};
        }
        return result;
    }
    
    int rotateLeft(int start, int rotation)
    {
        return (start - rotation + 100) % 100;
    }

int rotateRight(int start, int rotation)
    {
        return (start + rotation) % 100;
    }