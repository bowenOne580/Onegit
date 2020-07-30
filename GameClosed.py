import os
import time

command1 = 'taskkill /f /t /im AssassinsCreed_Dx9.exe'
command2 = 'taskkill /f /t /im CivilizationVI_DX12.exe'
command3 = 'taskkill /f /t /im eurotrucks2.exe'
command4 = 'taskkill /f /t /im TheEscapists2.exe'
command5 = 'taskkill /f /t /im msedge.exe'
command6 = 'taskkill /f /t /im Poly Bridge 2.exe'

i = 0
a = input("Press 1 to start this process..."+"\n")

if a == '1':
    print("starting service...")
    while i <= 1200:
        i += 1
        time.sleep(1)
        print("Time Left:"+str(1200-i))

if i == 1201:
    os.system(command1)
    os.system(command2)
    os.system(command3)
    os.system(command4)
    os.system(command5)
    os.system(command6)
