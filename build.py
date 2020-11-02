import subprocess
import os
import shutil
import argparse

cmakeCommand = ['cmake', '-G', 'Unix Makefiles', '-DCMAKE_BUILD_TYPE=Release', '..']
makeCommand = ['make', '-j4']
makeCleanCommand = ['make', 'clean']


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Python build script')
    parser.add_argument('--force', '-f', action='store_const', dest='force', const=True,
        help='force the rebuild of the program')
    parser.add_argument('--clean', '-c', action='store_const', dest='clean', const=True,
        help='Clean the project and build directory')
    args = parser.parse_args()

    if (args.clean):
        try:
            shutil.rmtree('./compilation')
        except FileNotFoundError:
            pass
        os._exit(0)
    print("Python build script")
    try:
        os.mkdir("compilation")
    except FileExistsError:
        print("Building folder already exists... rebuilding? use the -f option")
    os.chdir('./compilation')
    if args.force:
        result = subprocess.run(makeCleanCommand)
    result = subprocess.run(cmakeCommand)
    with open('error_output.txt', 'w') as fileHandler:
        result = subprocess.run(makeCommand, stderr=fileHandler)
    os.chdir('../')
    if (not os.path.exists('./compilation/sample')):
        result .returncode = 69
        print("The executable was not created!")
    else:
        result = subprocess.run(['python', 'tools/warnings.py'])
    
    if result.returncode != 0:
        print("Error when compiling the project")
        print("Error value:" + str(result.returncode))

