Cplusplus
=========

C++ files
Note: Implicit inlining abound. I chose to write these files with implicit inlining because:  
1. they are not exposed as interfaces, so having all the code in a single cpp file will not be potentially  
   abused by clients  
2. they are not part of a large compilation unit, so will not introduce excessive code duplication or 
   trigger recompilation of large blocks of code  
3. saves me programming time especially during a timed assignment  

Comments? Email me at alexisc [at] cs [dot] unc [dot] edu