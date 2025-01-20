#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class Timer {
private:
    int hours, minutes, seconds;
    std::atomic<bool> running; 

    void decrement() {
        while (running && (hours > 0 || minutes > 0 || seconds > 0)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (seconds > 0) {
                --seconds;
            } else {
                if (minutes > 0) {
                    --minutes;
                    seconds = 59;
                } else if (hours > 0) {
                    --hours;
                    minutes = 59;
                    seconds = 59;
                }
            }
            displayTime();
        }
        if (running) {
            std::cout << "\nTimer Finished!\n";
        }
    }

    void displayTime() {
        std::cout << "\r" << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << ":"
                  << (seconds < 10 ? "0" : "") << seconds << " " << std::flush;
    }

public:
    Timer(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s), running(false) {}
    void start() {
        running = true;
        std::thread timerThread(&Timer::decrement, this); // Thread 
        timerThread.detach(); // Jalankan thread
    }
    void stop() {
        running = false;
    }
};

int main() {
    int hours, minutes, seconds;
    std::cout << "Enter timer duration (hours minutes seconds): ";
    std::cin >> hours >> minutes >> seconds;

    Timer myTimer(hours, minutes, seconds);
    myTimer.start();
    std::cout << "Press Enter to stop the timer.\n";
    std::cin.ignore(); 
    std::cin.get();    

    myTimer.stop();
    std::cout << "Timer Stopped.\n";

    return 0;
}
