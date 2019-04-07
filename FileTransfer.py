import os
import sys


def transfer(platform, contestcode, problemcode, problemtype):
    global path
    if platform == 'Codechef':
        path = str(open('pathToFolder.txt').read().splitlines()[0].split('= ')[1])
    elif platform == 'Codeforces':
        path = str(open('pathToFolder.txt').read().splitlines()[1].split('= ')[1])
    elif platform == 'Hackerearth':
        path = str(open('pathToFolder.txt').read().splitlines()[2].split('= ')[1])
    elif platform == 'Hackerrank':
        path = str(open('pathToFolder.txt').read().splitlines()[3].split('= ')[1])

    path = path.replace('\\', '/')
    if path[-1] != '/':
        path += '/'

    if not os.path.exists(path + contestcode):
        os.makedirs(path + contestcode)

    folderpath = '"' + path + contestcode + '/"'
    command = 'copy ' + '"codes\\' + problemcode + problemtype + '" ' + folderpath
    if sys.platform == 'linux' or sys.platform == 'darwin':
        command = 'cp ' + '"codes/' + problemcode + problemtype + '" ' + folderpath
        
    os.system(command)