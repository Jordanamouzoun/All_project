##
## EPITECH PROJECT, 2023
## python_learning
## File description:
## ls1.py
##
verif = 1
anne = input("Saisissez l'anné : ")
anne = int(anne)
if anne % 4 == 0:
    if anne % 100 == 0:
        if anne % 400 == 0:
            print("c'est une anné bissextile.")
        else:
            print("ce n'est pas une anné bissextile.")
    else:
        print("ce n'est pas une anné bissextile.")
else:
    print("ce n'est pas une anné bissextile.")
