#include "uartController.h"

#include <iostream>

// Main function for UART communication example
int main(int argc, char* argv[]) {
    // Check if the UART device is provided as a command-line argument
    if (argc < 2) {
        std::cerr << "Please provide the UART device." << std::endl;
        std::cerr << "Example: ./uart-ctl /dev/ttymxc0" << std::endl;
        return 1;
    }

    // Extract the UART device name from the command-line arguments
    const char* device = argv[1];

    // Create an instance of the UARTController with the specified device name
    UARTController uartController(device);

    // Open the UART port
    if (!uartController.openUART()) {
        return 1;
    }

    // Data to be sent through UART
    const char* data = "Hello, UART!";

    // Send data through UART
    if (!uartController.send(data)) {
        // Close the UART port if sending fails
        uartController.closeUART();
        return 1;
    }

    // Receive data from UART
    if (!uartController.receive()) {
        // Close the UART port if receiving fails
        uartController.closeUART();
        return 1;
    }

    // Close the UART port
    uartController.closeUART();

    return 0;
}