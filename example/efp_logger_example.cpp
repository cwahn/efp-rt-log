#include <string>

#include "efp/logger.hpp"

int main() {
    using namespace efp;

    // Optional log level setting. Default is LogLevel::Info
    Logger::set_log_level(LogLevel::Trace);

    // Optional log period setting. Default is 20ms
    // Logger::set_log_period(std::chrono::milliseconds(1000));`

    // Optional log output setting. // default is stdout
    // Logger::set_output("./efp_logger_test.log");
    // Logger::set_output(stdout);

    printf("sizeof PlainMessage %lu bytes\n", sizeof(detail::PlainMessage));
    printf("sizeof FormatedMessage %lu bytes\n", sizeof(detail::FormatedMessage));
    printf("The size of LogData: %lu bytes\n", sizeof(detail::LogData));
    printf("sizeof std::string %lu bytes\n", sizeof(std::string));

    int x = 42;

    // Use the logging functions
    trace("This is a trace message with no formating");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    debug("This is a debug message with a pointer: {}", (void*)&x);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    info("This is a info message with a float: {}", 3.14f);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    warn("This is a warn message with a int: {}", 42);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    error("This is a error message with a string literal: {}", "error");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // ! Sending std::string to the buffer is O(n) and may increase risk of buffer overflow
    // ! Every 20 ~ 30 char will take one buffer space.
    fatal("This is a fatal message with a std::string: {}", std::string("fatal error"));

    // const auto lorem_ipsum = std::string("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    // info("This is a info message with a long string: {}", lorem_ipsum);
    // const auto a_1000 = std::string(1000, 'a');
    // info("This is a info message with a 1000 char string: {}", a_1000);
    // info("Does it support Korean? {}", "한글도 되나요?");
    // info("This is a info message with a empty string: {}", std::string(""));

    return 0;
}