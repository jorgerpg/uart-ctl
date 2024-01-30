# UART Communication Library

A simple library for UART communication in C#.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [API Reference](#api-reference)
- [Contributing](#contributing)
- [Contact](#contact)

## Introduction

The UART Communication Library provides a straightforward implementation for serial communication using the UART (Universal Asynchronous Receiver-Transmitter) protocol in C#. It includes features for opening, closing, sending, and receiving messages over a serial port.

## Installation

To use the UART Communication Library, follow these steps:

1. Include the `UartCommunication.cs` file in your C# project.
2. Ensure that your project has the required dependencies for threading and serial communication.
3. Instantiate the `UartCommunication` class with the desired port name and baud rate.

## Usage

To use the UART Communication Library, follow these steps:

1. Create an instance of the `UartCommunication` class with the appropriate parameters.
2. Open the serial port using the `Open` method.
3. Start reading data from the serial port in a separate thread using the `StartReading` method.
4. Use the `SendMessage` method to send messages over the serial port.
5. Optionally, handle received messages in the `SerialPortDataReceived` method.
6. Compile and execute.

## Example

```csharp
using System;

namespace UartCommunication
{
    class Program
    {
        static void Main(string[] args)
        {
            // Check if the device name is provided as a command-line argument
            if (args.Length < 1)
            {
                Console.WriteLine("You need to provide the device name as a command-line argument.");
                return;
            }

            string deviceName = args[0];

            // Create an instance of UartCommunication with the specified device name and baud rate
            UartCommunication communication = new UartCommunication(deviceName, 115200);

            // Open the serial port
            communication.Open();

            // Start reading data from the serial port in a separate thread
            communication.StartReading();

            Console.WriteLine("Type 'exit' to terminate the program.");

            while (true)
            {
                // Receive input from the user
                string message = Console.ReadLine();

                // Exit the program if the command is "exit"
                if (string.Equals(message, "exit", StringComparison.OrdinalIgnoreCase))
                {
                    break;
                }

                // Send the user input as a message
                communication.SendMessage(message);
            }

            // Close the serial port before exiting the program
            communication.Close();
        }
    }
}
```

## API Reference

The UART Communication Library provides the following methods:

- `UartCommunication(string portName, int baudRate)`: Constructor to initialize the serial port with the specified parameters.
- `void Open()`: Opens the serial port.
- `void Close()`: Closes the serial port.
- `void SendMessage(string message)`: Sends a message over the serial port.
- `void StartReading()`: Starts reading data from the serial port in a separate thread.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request in the repository.

## Contact

For any questions or further assistance, please feel free to contact the maintainers:

* [Jorge Ricarte Passos Gonçaalves](jorge.goncalves@fbest.org.br)