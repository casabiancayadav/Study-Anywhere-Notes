

( # ) BBB can boot from two many ways. Like eMMC, SD Card, UART, SPI, USB . 
	  But generally two methods are prominat those are eMMC and SD Card.
( # ) BBB uses TI processor namely SITARA Series uses ARM. Write down ARM  
( # ) Enable internet over USB.

( # ) Device number is the Number which is assigen to every attached 
	  Device Driver to Linux kernal.
       (##) Device Number is 32 bit number. Whose First 12 bits are for 
			Major number and remaining 20 bits are for minor number.
       (##) Major number is attached to the specific devise driver where
			as minor number represent the attached instances. 
            i.e For RTC devices there is only one Driver in OS and Mjoar number will represent this Driver. But connected RTC devices can be more than one.
                So these instances will be represented by minor Number.

( # ) All device Driver are under /dev catagory. There are two type of 
	  Divice Driver namely Static and Dynamic Device Driver.
        (##) Static device Drivers are those Drivers which attached with 
			 kernal during Boot time.
        (##) Dynamic device Drivers  are those Drivers which can we 
			 attached duing run time. these are called Dynamicaly Loadable kernal Modules(LKM).
( # ) Character device Drivers are those Drivers which sends data character by character.
( # )  Structure related to File operations are declared into include\linux\fs.h
( # )  Error handling macroes can be found in include/linux/err.h
( # ) 
( # )

*************************cross tool-chain installation and settings for linux host******************

STEP 1 : Download arm cross toolchain for your Host machine

STEP 2 :  export  path of the cross compilation toolchain. 

export PATH=$PATH:/home/kiran/BBB_Workspace/Downloads/gcc-linaro-6.3.1-2017.02-x86_64_arm-linux-gnueabihf/bin


*************************U-boot Compilation ***************************************************


STEP 1: distclean : deletes all the previously compiled/generated object files. 

make CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2 : apply board default configuration for uboot

make CROSS_COMPILE=arm-linux-gnueabihf- am335x_boneblack_defconfig


STEP 3 : run menuconfig, if you want to do any settings other than default configuration . 

make CROSS_COMPILE=arm-linux-gnueabihf-  menuconfig


STEP 4 : compile 

make CROSS_COMPILE=arm-linux-gnueabihf- -j4  // -j4(4 core machine) will instruct the make tool to spawn 4 threads
make CROSS_COMPILE=arm-linux-gnueabihf- -j8  // -j8(8 core machine) will instruct the make tool to spawn 8 threads


************************* linux compilation ***************************************************
STEP 1:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bb.org_defconfig (4.4)
for 4.11 use omap2plus_defconfig

STEP 3:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

STEP 4:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs LOADADDR=0x80008000 -j4

STEP 5:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules

STEP 6:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path of the RFS> modules_install


( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )
( # )

  