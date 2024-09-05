import random

random.seed(42)     # replicable seed value

MAX_SIZE = 10 * 10**6
MIN_SIZE = 10**3
MAX_INT = 2**16 
SCALE_FACOTR = 10

file_index = 1
i = MIN_SIZE
while (i <= MAX_SIZE):
    file = open('input_%i.txt' % file_index, 'w')
    A = [str(random.randint(1, MAX_INT)) for k in range(1, i+1)] 
    file.write((" ").join(A))
    file.write("\n")
    file_index += 1
    i *= SCALE_FACOTR 
    file.close()

