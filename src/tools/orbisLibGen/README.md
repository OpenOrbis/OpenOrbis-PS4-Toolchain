# OrbisLibGen
## Version 1.10

This python script is used to generate stub files and include/orbis headers for an Open Source SDK!

This tool was written by **CrazyVoid**

If you wish to contribute to this tool, please verify or attempt to verify it works on all platforms before pushing changes
Windows, Linux, Mac


### Steps to use this tool

##### 1 Download a version of IDC Lib Documentation
##### 2 Unzip in the same folder as OrbisLibGen
##### 3 Run **python genlib.py path/to/sprx/folder **
##### 4 Run **python gen_makefile.py**
##### 5 CMD **cd build & make**

### To Install Build Files
##### 1 Copy all *.h to <OO_PS4_TOOLCHAIN>/include/orbis folder
##### 2 Copy all *.so to <OO_PS4_TOOLCHAIN>/lib folder
##### ALL DONE :D

### Todo
##### 1 need to implement a **make install**
##### 2 need to implement prx vars at some point
##### 3 clean up the code some more in areas

Once you run the script it will generate a folder full of .S 
You'll need to manually compile these using gcc at the moment until the makefile is fixed!
