import math
import random
from time import sleep
import os

def zcasino():
    compte = 1000
    while 1:
        print("**************************Bonjour et bienvenue au Zcasino**************************\n\n\nVous avez actuellement ", compte, "$ sur votre compte")
        while 1:
            num_mise = input("\n\n Veillez miser sur un numero compris entre 0 et 49 :")
            try:
                num_mise = int(num_mise)
                if num_mise < 0 or num_mise >= 50:
                    print("Error!!! Le numero choisi n'est pas compris entre 0 et 49")
                    continue
            except ValueError:
                print("Error!!! Vous n'avez pas saisi un nombre.")
                continue
            break
        while 1:
            mise = input("\n\nJe vous prie de entrer la somme que vous souhaitez miser: ")
            try:
                mise = int(mise)
                if mise < 0:
                    print("Error!!! La somme misée est inférieur à zéro.")
                    continue
                if mise > compte:
                    print("Vous n'avez pas assez d'argent sur votre compte! VOUS avez que ", compte, "$")
                    continue
            except ValueError:
                print("Error!!! Vous n'avez pas saisi un nombre.")
                continue
            break
        print("Lancement de la roulette ...")
        sleep(3)
        num_ale = random.randrange(50)
        print("Le numero gagnant est le ", num_ale)
        if num_ale == num_mise:
            compte += num_mise * 3
            print("Vous avez le numero gagnant! Vous remportez donc ", num_mise * 3, "$")
        elif ((num_mise % 2 == 0 and num_ale % 2 == 0) or (num_mise % 2 != 0 and num_ale % 2 != 0)):
            compte += math.ceil(mise / 2)
            print("Le numero gagnant est de même couleur que celui misé. Vous remportez donc ", math.ceil(mise / 2), "$")
        else:
            print("Désolé, vous avez perdu.")
            compte -= mise
        print("Vous avez donc", compte, "$ sur votre compte")
        if compte == 0:
            print("Ah bro tu es ruiné hein, tu n'as plus d'argent sur ton compte.")
            break
        loi = input("Appuyez sur *entrer* pour rententez votre chance. Appuyez sur Q pour quitter le casino: ")
        if (loi == 'q'):
            break
        else:
            os.system("clear")
            continue
zcasino()
