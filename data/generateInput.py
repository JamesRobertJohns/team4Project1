import random
import sys

random.seed(42)     # replicable seed value

MAX_SIZE = 10 * 10**6
MIN_SIZE = 10**3
MAX_INT = 2**31 - 1  
SCALE_FACOTR = 10

file_index = 1
i = MIN_SIZE
while (i <= MAX_SIZE):
    try:
        file = open('input_%i.txt' % file_index, 'w')
        # raise OSError("Assert false")
    except OSError:
        print("[-] Error in writing file 'input_%i.txt'" % file_index)
        sys.exit()

    A = [str(random.randint(1, MAX_INT)) for k in range(1, i+1)] 
    file.write(("\n").join(A))
    file.write("\n")
    file_index += 1
    i *= SCALE_FACOTR 
    file.close()
    msg = "[+] input_{0}.txt generated. number of elements is {1}."  
    print(msg.format(file_index-1, i)) 

