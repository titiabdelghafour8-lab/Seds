#include <chrono>
#include <iostream>
#include <string>
#include <deque>


#include <random>

int randomBetween0and1() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 1);
    return dist(gen);
}

int main() {
    std::deque<std::string> buffer;
    int lineCounter = 0;
    std::string currentLine { };
    while (lineCounter < 200){

        static const std::string lineValues[2] = { "hih", ""};
        int index = randomBetween0and1();
        currentLine = lineValues[index];
        buffer.push_back(currentLine);
        lineCounter++;

        if (lineCounter > 42) {
            if (currentLine.empty()) {
                std::cout << "Match found! Line " << lineCounter - 42
                        << ": " << buffer.front() << std::endl;
            }
        }

        if (buffer.size() > 42) {
            buffer.pop_front();
        }
    }

    return 0;

}
