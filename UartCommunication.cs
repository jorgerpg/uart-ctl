using System;
using System.IO.Ports;
using System.Text.RegularExpressions;
using System.Threading; // Import the Thread namespace

namespace UartCommunication
{
    public class UartCommunication
    {
        private SerialPort _serialPort;

        // Constructor to initialize the SerialPort with specified parameters
        public UartCommunication(string portName, int baudRate)
        {
            _serialPort = new SerialPort(portName, baudRate);
        }

        // Method to open the serial port
        public void Open()
        {
            try
            {
                _serialPort.Open();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error opening serial port: " + ex.Message);
            }
        }

        // Method to close the serial port
        public void Close()
        {
            _serialPort.Close();
        }

        // Method to send a message through the serial port
        public void SendMessage(string message)
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.WriteLine(message);
            }
        }

        // Method to start reading data from the serial port in a separate thread
        public void StartReading()
        {
            Thread readThread = new Thread(SerialPortDataReceived);
            readThread.Start();
        }

        // Method that runs in a separate thread to handle data received from the serial port
        private void SerialPortDataReceived()
        {
            while (_serialPort.IsOpen)
            {
                string receivedData = _serialPort.ReadExisting();

                if (!string.IsNullOrEmpty(receivedData))
                {
                    Console.WriteLine(receivedData);
                }

                Thread.Sleep(100); // Introduce a small delay to avoid busy waiting
            }
        }
    }
}