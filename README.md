# LZ78-algorithm
LZ78-data compression algorithm(Originally executed in Dev-C++ IDE)

Note: Use special characters in place of spaces.

Explanation:
    
     1)This algorithm is based on LZ78 data compression technique.
     2)If, at the end, the encountered symbol is already there in dictionary, it will put '-' to represent the end of file.
     
Sample Input:
      
       Enter the string:abracadabrarrarra
      
Sample Output:

         ENCODER                 INDEX          ENTRY
        < 0 , a >                1              a
        < 0 , b >                2              b
        < 0 , r >                3              r
        < 1 , c >                4              ac
        < 1 , d >                5              ad
        < 1 , b >                6              ab
        < 3 , a >                7              ra
        < 3 , r >                8              rr
        < 1 , r >                9              ar
        < 7 , - >                10
        
        decoded string:abracadabrarrarra
      
