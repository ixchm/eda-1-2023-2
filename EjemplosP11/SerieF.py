def recur_fibo(n):
    if n<=1:
        return n
    else:
        return(recur_fibo(n-1)+ recur_fibo(n-2))
nterms = 17     #Tamaño de la serie

if nterms<= 0:
    print("Ingrese un entero positivo")
else:
    print("secuencia Fibonacci:")
    for i in range(nterms):
        print(recur_fibo(i))
