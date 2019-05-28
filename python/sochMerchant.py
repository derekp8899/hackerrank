 #!/bin/python

 import math
 import os
 import random
 import re
 import sys

 # Complete the sockMerchant function below.
 def sockMerchant(n, ar):
     if n == 0 || n == 1:
         return socks
     for i in range(n):
         for j in range(i, n):
             if  ar[i]==ar[j]:
                 ar.pop(i)
                 ar.pop(j)
                 socks+=1
                 sockMerchant(n-2,ar)
    return socks


 if __name__ == '__main__':
     fptr = open(os.environ['OUTPUT_PATH'], 'w')
     
     n = int(raw_input())
     
     ar = map(int, raw_input().rstrip().split())
     
     result = sockMerchant(n, ar)
     
     fptr.write(str(result) + '\n')
     
     fptr.close()
         
