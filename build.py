import subprocess
import os

cmakeCommand = ['cmake', '-G', 'Unix Makefiles', '-DCMAKE_BUILD_TYPE=Release', '..']
makeCommand = ['make', '-j4']


if __name__ == "__main__":
    print("Python build script")
    os.mkdir("compilation")
    os.chdir('./compilation')
    result = subprocess.run(cmakeCommand)
    with open('error_output.txt', 'w') as fileHandler:
        result = subprocess.run(makeCommand, stderr=fileHandler)
    os.chdir('../')
    result = subprocess.run(['python', 'tools/warnings.py'])
    
    if result != 0:
        print("Error when compiling the project")

