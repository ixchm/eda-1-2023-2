import matplotlib.pyplot as plt
import random

def insertionSort(n_lista):
    times = 0
    for index in range(1, len(n_lista)):
        actual = n_lista[index]
        posicion = index
        while (posicion > 0 and n_lista[posicion - 1] > actual):
            n_lista[posicion] = n_lista[posicion - 1]
            posicion = posicion - 1
            times += 1
        n_lista[posicion] = actual
    return times

def quickSort(n_lista):
    if len(n_lista) <= 1:
        return 0
    pivot = n_lista[len(n_lista) // 2]
    left = [x for x in n_lista if x < pivot]
    right = [x for x in n_lista if x > pivot]
    return quickSort(left) + quickSort(right) + 1

def mergeSort(n_lista):
    if len(n_lista) <= 1:
        return 0
    mid = len(n_lista) // 2
    left = n_lista[:mid]
    right = n_lista[mid:]
    return mergeSort(left) + mergeSort(right) + 1

def selectionSort(n_lista):
    times = 0
    for i in range(len(n_lista)):
        min_index = i
        for j in range(i + 1, len(n_lista)):
            if n_lista[j] < n_lista[min_index]:
                min_index = j
                times += 1
        n_lista[i], n_lista[min_index] = n_lista[min_index], n_lista[i]
    return times

def bubbleSort(n_lista):
    times = 0
    for i in range(len(n_lista)):
        for j in range(len(n_lista) - 1):
            if n_lista[j] > n_lista[j + 1]:
                n_lista[j], n_lista[j + 1] = n_lista[j + 1], n_lista[j]
                times += 1
    return times

TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y_insertion = []
eje_y_quicksort = []
eje_y_mergesort = []
eje_y_selectionsort = []
eje_y_bubblesort = []

for num in eje_x:
    lista_variable = random.sample(range(0, 100), num)
    print(lista_variable)

    times_insertion = insertionSort(list(lista_variable))
    eje_y_insertion.append(times_insertion)

    times_quicksort = quickSort(list(lista_variable))
    eje_y_quicksort.append(times_quicksort)

    times_mergesort = mergeSort(list(lista_variable))
    eje_y_mergesort.append(times_mergesort)

    times_selectionsort = selectionSort(list(lista_variable))
    eje_y_selectionsort.append(times_selectionsort)

    times_bubblesort = bubbleSort(list(lista_variable))
    eje_y_bubblesort.append(times_bubblesort)

print(eje_y_insertion)
print(eje_y_quicksort)
print(eje_y_mergesort)
print(eje_y_selectionsort)
print(eje_y_bubblesort)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x, eje_y_insertion, marker="o", color="b", linestyle='-', label="Insertion Sort")
ax.plot(eje_x, eje_y_quicksort, marker="o", color="r", linestyle='-', label="QuickSort")
ax.plot(eje_x, eje_y_mergesort, marker="o", color="g", linestyle='-', label="MergeSort")
ax.plot(eje_x, eje_y_selectionsort, marker="o", color="m", linestyle='-', label="Selection Sort")
ax.plot(eje_x, eje_y_bubblesort, marker="o", color="c", linestyle='-', label="Bubble Sort")

ax.set_xlabel("Tamaño de la lista")
ax.set_ylabel("Número de operaciones")
ax.grid(True)
ax.legend()

plt.title("Rendimiento de los algoritmos de ordenamiento")
plt.show()