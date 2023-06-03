def decBin(n):
    if n < 2:
        print(n, end='')
    else:
        decBin(n // 2)
        print(n % 2, end='')


def convertir_decimal_binario():
    n = int(input("Introduzca un número: "))
    if n < 0:
        print("El número debe ser positivo.")
        convertir_decimal_binario()
    else:
        print("Binario:", end=' ')
        decBin(n)


def recur_serfi(n):
    if n <= 1:
        return n
    else:
        return recur_serfi(n - 2) + recur_serfi(n - 1)


def menu():
    while True:
        print("\n\n.:*****MENU*****:.\n")
        print("1 - Conversión de decimal a binario")
        print("2 - Serie de Fibonacci")
        print("3 - Salir")

        opcion = int(input("\nIngrese la opción deseada:\n"))

        if opcion == 1:
            print("\n.:*****CONVERSIÓN DE DECIMAL A BINARIO*****:.\n")
            convertir_decimal_binario()
        elif opcion == 2:
            print("\n.:*****SERIE DE FIBONACCI DE FORMA INVERSA*****:.\n")
            nterms = int(input("Ingrese el tamaño de la serie de Fibonacci:\n"))

            if nterms <= 0:
                print("Ingrese un entero positivo")
            else:
                print("\nLa secuencia Fibonacci inversa es:")
                for i in range(nterms - 1, -1, -1):
                    print(recur_serfi(i))
        elif opcion == 3:
            print("Gracias por usar el programa")
            break
        else:
            print("Opción inválida. Intente nuevamente.")


menu()