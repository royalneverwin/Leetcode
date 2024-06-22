from decimal import Decimal, getcontext

def main():
    getcontext().prec = 50
    s = input()[2:]
    ans = Decimal(int(s, 8))
    ans /= 8 ** len(s)
        
    print(f'0.{s} [8] = {ans:f} [10]')
    return
if __name__ =='__main__':
    main()
