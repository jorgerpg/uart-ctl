# UART Communication Library (C++)

A simple C++ library for UART communication.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [API Reference](#api-reference)
- [Contributing](#contributing)
- [Contact](#contact)

## Introduction

The UART Communication Library in C++ provides an easy-to-use implementation for serial communication using the UART (Universal Asynchronous Receiver-Transmitter) protocol. It includes features for opening, closing, sending, and receiving messages over a UART port.

## Installation

To use the UART Communication Library, follow these steps:

1. Include the `uartController.h` and `uartController.cpp` files in your C++ project.
2. Ensure that your project has the required dependencies for file handling, terminal input/output, and UART communication.
3. Create an instance of the `UARTController` class with the desired UART device name.

## Usage

To use the UART Communication Library, follow these steps:

1. Create an instance of the `UARTController` class with the appropriate UART device name.
2. Open the UART port using the `openUART` method.
3. Send data using the `send` method.
4. Receive data using the `receive` method.
5. Close the UART port using the `closeUART` method when done.

## Example

```cpp
#include "uartController.h"

#include <iostream>

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
```

## API Reference

The UART Communication Library in C++ provides the following methods:

- `UARTController(const char* device)`: Constructor to initialize the UART port with the specified device name.
- `bool openUART()`: Opens the UART port.
- `void closeUART()`: Closes the UART port.
- `bool send(const char* data)`: Sends data over the UART port.
- `bool receive()`: Receives data from the UART port.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request in the repository.

## Contact

For any questions or further assistance, please feel free to contact the maintainers:

- [Jorge Ricarte Passos Gonçalves](jorgericartepg@gmail.com)