import subprocess
import os
import shutil
import argparse

cmakeCommand = ['cmake', '-G', 'Unix Makefiles', '-DCMAKE_BUILD_TYPE=', '..']
makeCommand = ['make', '-j4']
makeCleanCommand = ['make', 'clean']

valid_build_type = ['debug', 'release']


if __name__ == "__main__":
    print("Python build script")
    parser = argparse.ArgumentParser(description='Python build script')
    parser.add_argument('-b', '--build', dest='build_type',
        action='store', required=False, default='debug',
        help="The build type to run: [" + ','.join(valid_build_type) + "]. Default=debug")
    parser.add_argument('-f', '--force', action='store_const', dest='force', const=True,
        help='force the rebuild of the program')
    parser.add_argument('-c', '--clean', action='store_const', dest='clean', const=True,
        help='Clean the project and build directory')

    args = parser.parse_args()

    if (args.clean):
        try:
            shutil.rmtree('./compilation')
        except FileNotFoundError:
            pass
        os._exit(0)

    try:
        os.mkdir("compilation")
    except FileExistsError:
        print("Building folder already exists... rebuilding? use the -f option")
    os.chdir('./compilation')
    if args.force:
        result = subprocess.run(makeCleanCommand)
    
    if (args.build_type in valid_build_type):
        cmakeCommand[-2] = cmakeCommand[-2] + args.build_type.upper()
    else:
        cmakeCommand[-2] = cmakeCommand[-2] + valid_build_type[0]

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

