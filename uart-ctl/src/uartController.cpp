#include "uartController.h"

#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>

// Constructor for UARTController, initializing uart to -1
// and setting the device name
UARTController::UARTController(const char* device) : uart(-1), device(device) {}

// Function to open the UART port
bool UARTController::openUART() {
    // Open the UART port with read and write access,
    // without controlling terminal and non-blocking mode
    uart = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
    
    if (uart == -1) {
        std::cerr << "Error opening the UART port." << std::endl;
        return false;
    }

    // Configure the UART port settings
    struct termios options;
    tcgetattr(uart, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD; // Baud rate, 8-bit data, no modem control, enable receiver
    options.c_iflag = 0; // Disable input processing
    options.c_oflag = 0; // Disable output processing
    options.c_lflag = 0; // Disable line processing
    tcflush(uart, TCIFLUSH); // Flush the input buffer
    tcsetattr(uart, TCSANOW, &options); // Apply the new settings

    return true;
}

// Function to close the UART port
void UARTController::closeUART() {
    if (uart != -1) {
        close(uart);
        uart = -1;
    }
}

// Function to send data through the UART port
bool UARTController::send(const char* data) {
    if (uart == -1) {
        std::cerr << "UART port is not open." << std::endl;
        return false;
    }

    // Write data to the UART port
    ssize_t bytesWritten = write(uart, data, strlen(data));
    
    if (bytesWritten == -1) {
        std::cerr << "Error sending data through UART." << std::endl;
        return false;
    }

    return true;
}

// Function to receive data from the UART port
bool UARTController::receive() {
    if (uart == -1) {
        std::cerr << "UART port is not open." << std::endl;
        return false;
    }

    // Read data from the UART port into a buffer
    char buffer[256];
    ssize_t bytesRead = read(uart, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) {
        std::cerr << "Error reading data from UART." << std::endl;
        return false;
    }

    buffer[bytesRead] = '\0'; // Null-terminate the received data
    std::cout << "Received data: " << buffer << std::endl;

    return true;
}