inventario={"FV00M":["MANGO",56,200],"BL00DJ":["DON JULIO",1075,100],"BL00MD":["MAESTRO DOBEL",659,100],#Mayusculas facilita comparar las cadenas
            "BL00JW":["JOHNIE WALKER",325,100],"AB00CC":["CHILES CHIPOTLES",253,100],"AB00AVA":["ACEITE VEGETAL AURRERA",35, 100]
            }
cola=[]

empleados={"ROCIO DURCAL":["RD00G","GERENTE"],"JOSE JOSE":["JJ00C","CAJERO"]}

#Imprimir Inventario despues de agregar 
def imprimir_emp():
    global empleados # global se puede acceder y modificar tanto dentro de la función como fuera de ella
    for nombre,datos in empleados.items():#items ayuda a recorrer el diccionario
        print(f"\n{''.join(str(nombre))} - {datos[0]} - {datos[1]}")


def agregar_emp(lista):#prefijo,puesto
    global empleados
    
    if lista[0]=="G":
        for x in empleados.items():
            if x[1][0].endswith("G"): #Endswith permite ver como termina una cadena de caracteres
                print("Ya hay un gerente, si quiere cambiarlo vaya a la opcion de cambio de puesto")
                return

    nombre=input("\nIngrese el nombre completo del trabajador: ").upper()        #se le pone .upper para que todas las pabras ingresadas sean mayusculas y faciliten en la funcion ordenar 

    if nombre not in empleados:
        nueva_palabra = "".join([letra[0] for letra in nombre.split()])   #se le .split para tomar las primeras letras despues de un espacio y del inicio 
        ID=nueva_palabra + "00" + lista[0]#prefijo iniciales de la nueva palabra y se le añade dos ceros
        empleados[nombre]=[ID,lista[1]]#puesto
        print("\nLa operacion fue exitosa")
        imprimir_emp()
    else:
         print("Este trabajador ya esta dado de alta")
         return


    

def Altas():
    print("Altas")
    lista=ElegirPuesto()
    agregar_emp(lista)
    
def ElegirPuesto():
    while True:
        menuSum=int(input("""

        \t1) Gerente
        \t2) Responsable de seccion 
        \t3) Empleados de seccion 
        \t4) Reponedor
        \t5) Cajero
        \t6) Almacen
        \t7) Empleado general
                

        Elija el puesto donde desea agregar: """))

        if menuSum==1:
            print("Escogio Gerente")
            lista=["G","GERENTE"] #G es el prefijo
            return(lista)
        
        elif menuSum==2:
            print("Escogio Responsable de seccion")
            lista=["RS","RESPONSABLE DE SECCION"]
            return(lista)
            
        elif menuSum==3:
            print("Escogio Empleado de seccion")
            lista=["ES","EMPLEADO DE SECCION"]
            return(lista)
            
        elif menuSum==4:
            print("Escogio Reponedor")
            lista=["R","REPONEDOR"]
            return(lista)
            
        elif menuSum==5:
            print("Escogio Cajero")
            lista=["C","CAJERO"]
            return(lista)
            
        elif menuSum==6:
            print("Escogio Almacen")
            lista=["A","ALMACEN"]
            return(lista)
            
        elif menuSum==7:
            print("Escogio Empledo general")
            lista=["EG","EMPLEADO GENERAL"]
            return(lista)

        else:
             print("Opcion invalida")
    


def Bajas():
    print("Bajas")
    global empleados
    borrar="borrar"
    cont=0
    if empleados:#Para ver si hay algo en el diccionario 
        empleadoBaja=input("\nIngrese el codigo o el nombre del empleado que desea dar de baja: ").upper()
        for x in empleados.items():
            if empleadoBaja==x[1][0] or empleadoBaja==x[0]:#1 es nombre 0 es codigo
                borrar=x[0] # borrar sera igual al nombre
                break
            else:
                cont+=1

        if cont==len(empleados):
            print("No se ha encontrado al trabajador")

        if borrar!="borrar":
            del empleados[borrar]
            print("\nLa operacion fue exitosa")
            imprimir_emp()
    
    else:
        print("No hay empleados dados de alta")

    

    

def CambiosDePuesto():
    print("Cambios de Puesto")
    global empleados
   # borrar="borrar"
    cont=0
    empleadoBaja=input("\nIngrese el codigo o el nombre del empleado del que desea cambiar su puesto: ").upper()
    for x in empleados.items():#recorre el diciconario 
        if empleadoBaja==x[1][0] or empleadoBaja==x[0]:
            print(f"Se encontro al empleado {x[0]}, tiene el puesto de {x[1][1]}")#1 1 es el puesto
            print("Ingrese el nuevo puesto")
            lista=ElegirPuesto()
            nombre=x[0]
            nueva_palabra = "".join([letra[0] for letra in nombre.split()])   #se le .split para tomar las primeras letras despues de un espacio y del inicio
            ID=nueva_palabra + "00" + lista[0]#prefijo
            empleados[nombre]=[ID,lista[1]]#puesto
            print("\nLa operacion fue exitosa")
            imprimir_emp()
        else:
            cont+=1

    if cont==len(empleados):
        print("No se ha encontrado al trabajador")
    



def AdministracionDePersonal():
    while True:
        menu=int(input("""
        \t\t\t---Administracion de personal---

        \t\tMenu:

        \t1) Altas
        \t2) Bajas
        \t3) Cambios de puesto
        4) Regresar 

        Elija la opcion deseada: """))

        if menu==1:
            Altas()
        elif menu==2:
            Bajas()
        elif menu==3:
            CambiosDePuesto()
        elif menu==4:
            break
        else:
            print("Opcion invalida")


#Funcion Agregar (la funcion Agregar suministros hace la llamada de esta funcion)
def agregar(prefijo):
    global inventario
    producto=input("\nIngrese el nombre del producto: ").upper()        #se le pone .upper para que todas las pabras ingresadas sean mayusculas y faciliten en la funcion ordenar 
    nueva_palabra = "".join([letra[0] for letra in producto.split()])   #se le .split para tomar las primeras letras despues de un espacio y del inicio
    ID=prefijo + "00" + nueva_palabra
    if ID in inventario:
        respuesta=int(input("Este producto ya se encuentra en el inventario ¿Desea Agregar mas?\n 1) si\n 2) no: "))
        while True:
                if respuesta==1:
                        newcant=int(input("Ingrese la cantidad (por piezas o kg): "))
                        inventario[ID][2]+=newcant #ID es código, 2 es nombre,precio,cantidad
                        respuesta2=int(input("¿Desea conservar el mismo precio?\n 1) si\n2) no: "))
                        while True:
                                if respuesta2==1:
                                        print("\nLa operacion fue exitosa")
                                        imprimir()
                                        return
                                elif respuesta2==2:
                                        newprecio=int(input("Ingrese el nuevo precio: "))
                                        inventario[ID][1]=newprecio
                                        print("\nLa operacion fue exitosa")
                                        imprimir()
                                        return
                                else:
                                        print("Opcion invalida")
                elif respuesta==2:
                        return
                else:
                        print("Opcion invalida")

    precio=int(input("Ingrese el precio del producto: "))
    cantidad=int(input("Ingrese la cantidad de productos: "))

    inventario[ID]=[producto,precio,cantidad]
    print("\nLa operacion fue exitosa")
    imprimir()

#Imprimir Inventario despues de agregar 
def imprimir():
    global inventario
    for cod,producto in inventario.items():
        print(f"\n{''.join(str(cod))} - {producto[0]} - {producto[1]} - {producto[2]}")



#Funcion Agregar Suministros
def Agregar_suministros():
    while True:
        menuSum=int(input("""
        \t\t\tElijio agregar suministros

        \t1) Bebidas y Licores
        \t2) Abarrotes
        \t3) Lacteos
        \t4) Frutas y Verduras
        \t5) Carnes Pescados y Mariscos
        \t6) Salchichoneria
        \t7) Panaderia y Tortilleria
        \t8) Congelados
        \t9) Limpieza del Hogar
        \t10) Cuidado de la Ropa
        \t11) Mascotas
        \t12) Bebes
        \t13) Farmacia
        \t14) Higiene y Belleza
        \t15) Jugueteria y Deportes
        \t16) Ropa y Zapateria
        \t17) Electronica
        
        18) Regresar

        Elija el departamento donde desea agregar: """))

        if menuSum==1:
            print("Escogio Bebidas y Licores")
            agregar("BL")
            
        elif menuSum==2:
            print("Escogio Abarrotes")
            agregar("AB")
            
        elif menuSum==3:
            print("Escogio Lacteos")
            agregar("LA")
            
        elif menuSum==4:
            print("Escogio Frutas y verduras")
            agregar("FV")
            
        elif menuSum==5:
            print("Escogio Carnes Pescados y Mariscos")
            agregar("CP")
            
        elif menuSum==6:
            print("Escogio Salchichoneria")
            agregar("SA")
            
        elif menuSum==7:
            print("Escogio Panaderia y Tortilleria")
            agregar("PT")
            
        elif menuSum==8:
            print("Escogio Congelados")
            agregar("CO")
            
        elif menuSum==9:
            print("Escogio Limpieza del hogar")
            agregar("LH")
            
        elif menuSum==10:
            print("Cuiddo de la ropa")
            agregar("CR")
            
        elif menuSum==11:
            print("Escogio Mascotas")
            agregar("MA")
            
        elif menuSum==12:
            print("Escogio Bebes")
            agregar("BB")
            
        elif menuSum==13:
            print("Escogio Farmacia")
            agregar("FA")
            
        elif menuSum==14:
            print("Escogio Higiene y Belleza")
            agregar("HB")
            
        elif menuSum==15:
            print("Escogio Jugueteria y Deportes")
            agregar("JD")
            
        elif menuSum==16:
            print("Escogio Ropa y Zapateria")
            agregar("RZ")
            
        elif menuSum==17:
            print("Escogio Electronica")
            agregar("EL")
            
        elif menuSum==18:
            break
        else:
            print("Opcion invalida")

def Quitar_suministros():
    global inventario
    if inventario:
        codigo=input("\nIngrese el codigo del producto que desea quitar: ").upper()
        if codigo in inventario:
            print(f"Este producto {inventario[codigo][0]}, cuenta con {inventario[codigo][2]} unidades")
            while True:
                cantidad=int(input("Ingrese la cantidad de productos que desea quitar: "))
                if cantidad == inventario[codigo][2]:
                    del inventario[codigo]#eliminar un elemento específico de el diccionario
                    print("La operacion fue exitosa")
                    imprimir()
                    break
                elif cantidad < inventario[codigo][2] and cantidad > 0:
                    inventario[codigo][2]-=cantidad
                    print("La operacion fue exitosa")
                    imprimir()
                    break
                elif cantidad > inventario[codigo][2] or cantidad < 1:
                    print("Error, la cantidad ingresada es mayor a la cantidad almacenada o es menor a cero")
                else:
                    print("Opcion invalida")
        else:
            print(f"No se encuentra el producto con el codigo {codigo} en el inventario")
    else:
        print("El inventario esta vacio")



def merge(arr, l, m, r, num_clave): #l indice izq r indice derecho
    n1 = m - l + 1
    n2 = r - m
 

    L = [0] * (n1)
    R = [0] * (n2)
 

    for i in range(0, n1):
        L[i] = arr[l + i] #ar=lista
 
    for j in range(0, n2):
        R[j] = arr[m + 1 + j]

    i = 0     
    j = 0     
    k = l
 
 
    while i < n1 and j < n2:
        if L[i][num_clave] <= R[j][num_clave]:#numclave=nombre
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
 

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
 

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
 
 
def Merge_Sort(lista,num_clave):
    mergeSort(lista,0,len(lista)-1,num_clave) #len->tamaño de la lista -1

def mergeSort(arr, l, r,num_clave):
    if l < r:
 
        m = l+(r-l)//2
 
        mergeSort(arr, l, m,num_clave)
        mergeSort(arr, m+1, r,num_clave)
        merge(arr, l, m, r,num_clave)

def imprimir_lis(lista):
     for x in lista:
          print(f"{x[0]} - {x[1]}")

def ordenar_xNombre():
     global inventario
     lista=[]
     for x,y in inventario.items():
        lista.append([x,y[0]])#y0 ordena nombre, .append manda al final
     num_clave=1
     Merge_Sort(lista,num_clave)
     imprimir_lis(lista)   


def ordenar_xCodigo():
     global inventario
     lista=[]
     for x,y in inventario.items():
        lista.append([x,y[0]])
     num_clave=0
     Merge_Sort(lista,num_clave)
     imprimir_lis(lista)

def Ordenar_suministros():
     global inventario
     opcion=int(input("Criterio:\n\n1. Nombre\n2. Codigo\n"))
     if opcion==1:
          ordenar_xNombre()
     elif opcion==2:
          ordenar_xCodigo()                               

#Menjo de inventario
def ManejoDeInventario():
    while True:

        menu=int(input("""
        \t\t\tSelecciono Manejo De Inventario

        \t1) Agregar Sumninistros
        \t2) Quitar Suministros
        \t3) Ordenar Suministros
        \t4) Regresar 

        Elija la opcion deseada: """))

        if menu==1:
            Agregar_suministros()
        
        elif menu==2:
            Quitar_suministros()
        
        elif menu==3:
            Ordenar_suministros()
        elif menu==4:
            break
        else:
            print("Opcion invalida")




def CobroDeProductos():
    global inventario
    lista=[]
    sum=0

    print("""Agregue los productos a su lista (para generar su ticket ingrese "T"):""")
    palabra="bandera"
    cant=1
    while palabra!="T":
        borrar="borrar"
        cont=0
        palabra=input().upper()
        for x in inventario.items():
            if palabra==x[1][0] or palabra==x[0]:
                if x[0].startswith("FV"):#verificar con que empieza
                    cant=int(input("Ingrese los kilos que desea agregar: "))
                    if cant <= x[1][2] and cant >0:
                         lista.append([x[0],x[1][0],x[1][1]*cant])
                         x[1][2]-=cant
                    else:
                         print(f"La cantidad de productos es mayor al que hay en tienda, por el momento solo disponemos de {x[1][2]} kg")
                else:
                    lista.append([x[0],x[1][0],x[1][1]])
                    x[1][2]-=1
                if x[1][2]==0:
                    borrar=x[0]
                    break
            else:
                cont+=1

        if borrar != "borrar":
            del inventario[borrar]

        if cont== len(inventario) and palabra != "T":
            print("Este producto no se encuentra en la tienda")


    if lista:
        print("Su lista esta compuesta de:\n")
        for x in lista:
            sum = sum + x[2]
            print(f"{x[0]} - {x[1]} - ${x[2]}")
        print(f"\nSu total a cobrar es de:\n{sum}")
    else:
        print("La lista esta vacia")



def AtencionClientes ():
    global cola
    global inventario
    producto=input("Ingrese el codigo del producto: ").upper()
    queja=input("Ingrese la queja respecto al producto: ")
    lista=[producto,queja]
    cola.append(lista)#lista anidada
    

def VerQuejas():
    global cola
    cont=0
    if cola:
         print("La lista esta mostrando del mas antiguo al mas reciente")
         for x in range(len(cola)):
             
            print(f"{cont+1}.- {cola[cont]}")
            cont+=1
    else:
         print("No hay quejas")


def Atencion_a_clientes():
     while True:
        menu=int(input("""
        \t\t\t---Atencion a clientes---

        \t\tMenu:

        \t1) Cobro de productos
        \t2) Atencion de clientes
        \t3) Ver quejas
        4) Regresar 

        Elija la opcion deseada: """))

        if menu==1:
            CobroDeProductos()
        elif menu==2:
            AtencionClientes()
        elif menu==3:
            VerQuejas()
        elif menu==4:
            break
        else:
            print("Opcion invalida")





#principal
while True:

    menu=int(input("""
    \t\t\t---Sistema de Administracion de Puma Abarrotero S.A de C.V.---

    \t\tMenu:

    \t1) Administracion de personal
    \t2) Manejo de inventario
    \t3) Atencion a clientes

    4)Salir

    Elija la opcion deseada: """))

    if menu==1:
        AdministracionDePersonal()
    elif menu==2:
        ManejoDeInventario()
    elif menu==3:
        Atencion_a_clientes()
    elif menu==4:
        break
    else:
        print("Opcion invalida")