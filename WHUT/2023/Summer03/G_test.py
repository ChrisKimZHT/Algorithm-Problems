for i in range(1, 21):
    bin_str = bin(i)[2:]
    bin_str = '0' * (i - len(bin_str)) + bin_str
    print(i, bin_str)
