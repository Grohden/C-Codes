#Importações
#Não importar o 'os' inteiro por problemas em 'open'
from os import walk
from os import startfile
from os import path
import datetime

#Aqui, são pegos os nomes e diretorio das musicas e dos diretorios (PEGARA SO OS ARQUIVOS, E OS NOMES DAS PASTAS JUNTO COM O CAMINHO)
f = []
for (dirpath, dirnames, filenames) in walk(input("Informe a pasta de Musicas:")): #se precisar altere, em um futuro pegara todas as musicas
    f.extend(filenames)
    break

#Lista todas as musicas no diretorio
for counter in range(0,len (filenames)-1):
	print (str(counter)+' '+filenames[counter])
	
#identifica o dia da semana para escrever no arquivo correto
def dayofweek():
    hoje = datetime.datetime.today().weekday()
    if hoje==0:
        hoje='seg'
    elif hoje==1:
        hoje='ter'
    elif hoje==2:
        hoje='qua'
    elif hoje==3:
        hoje='qui'
    elif hoje==4:
        hoje='sex'
    elif hoje==5:
        hoje='sab'
    elif hoje==6:
        hoje='dom'
    return hoje

#acha no arquivo se ja foi escrito o nome da musica e retorna um valor, caso ela não exista o valor voltado será -1 (o metodo find retorna -1 caso n encontre nada)
def achar():
    acha = open(lista,'r').read().find(filenames[int(escolha)])
    return acha

#Usa 'sair' para encerrar o programa
print('Para sair do programa digite "sair"')
escolha = ''

#loop do programa
while escolha != 'sair':
    try:
        escolha =int(input('Escolha a musica: '))
    except:
        print('porfavor, escolha uma musica pelo numero')

        
    #caso o usuario digite sair, ele sai.
    if escolha=="sair" or isinstance( escolha, int )==False:
        break
    
    #caso escolhida a musica, ele digita o nome dela, e a inicia em um player segundario(no meu caso VLC)
    else:
        print('Executando: '+filenames[int(escolha)])
        startfile(dirpath+'\\'+filenames[int(escolha)])

    #verifica o dia da semana e diz em qual(se existir(se não existir ele cria)) arquivo registrar, o formato do arquivo ñ importa, notepad abrira ele como texto
    hoje=dayofweek()
    lista=hoje+"_lista.smpl"
    if path.exists(lista):
        file = open(lista,'a') #se o arquivo existe ele o abre como append
    else:
        file = open(lista,'w+') #se não o cria e abre como write
    
    if achar()==-1:
        file.write(filenames[int(escolha)]+"\n")
    else:pass
    file.close()
    #repete o loop
