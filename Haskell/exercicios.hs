fib 0 = 0
fib 1 = 1
fib n=fib(n-1)+fib(n-2)



iguais a b  |a==b=0
            |a/=b=1
             
tres_iguais a b c |(iguais a b+iguais a c)==0=3
                  |(iguais a b+iguais a c+iguais b c)==2=2
                  |otherwise=0
                  
