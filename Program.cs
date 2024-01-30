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