
# I2C Protocol

1: Explain the I2C Protocol ?

2: Difference between I2C and SPI ?

3: What is Clock Stretching?

4: Draw the Clock Diagram of I2C protocol?

5: Can devices be added and removed while the system is running (Hot swapping) in I2C ?

Ans: Hot swapping is possible in I2C protocol.

6: What is the standard bus speed in I2C ?            

Ans: standard bus speed is 100Kbps  , fast mode is 400Kbps  , fast mode plus is 1Mbps , high speed mode is 4Mbps , Ultra speed mode is 5 Mbps

7: How many devices can be connected in a standard I2C communication ?

Ans: As per theoretically we can connect up to 127 devices for 7Bit  address and 2 ^10 devices will connect for 10Bit address. But practically depends on Capacitance load. If capacitance load is increase the speed will be reduced

8:  What is bus arbitration ? 

Ans: Arbitration is the process to avoid conflict the data on bus when multi master start communication at the same time.  In the arbitration – which is the lowest address of the salve, that salve will communication continues and other will be lost the arbitration

9: Advantages and limitations of I2C communication ?  

Ans: 1.Using I2C .. we can connect more slaves than SPI.  2.Cost effective compared to SPI.SPI 3.Different speeds available.  4.NO need of any GPIO pins. 5.hardware design implementation is simple than SPI because of 2 wire communication  6.Supports Multi master Communication  7. More complexity to write a program  8. Transfer of data speed(100 Kbps) is less than SPI(1 Mbps)

10: In read transaction, the master doesnot acknowledge the final byte it receives and issues STOP condition – True/False ?                                                
Ans: Yes, Read transaction master gives NACK before the stop condition.

11: 


# SPI Protocol

1: 
