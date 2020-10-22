import os
import sys

separationNumber = 60

if __name__ == "__main__":
    warningsFile = "compilation/error_output.txt"
    currentPath = '/'.join(os.getcwd().split('/')[-3:])
    projWarnings = []
    projErrors = []
    librariesWarningsNumber = 0
    librariesErrorsNumber = 0
    print("ProjectPath:*/", currentPath)
    for line in open(warningsFile, "r"):
        if currentPath in line:
            if ": error:" in line:
                projErrors.append(line)
            elif "warning" in line:
                projWarnings.append(line)
            else:
                pass
        elif ": error" in line:
            librariesErrorsNumber += 1
        elif "warning" in line:
            librariesWarningsNumber += 1
        else:
            # This line contains extra information about the warnings or errors
            pass
            
    for error in projErrors:
        print(error)
    for warning in projWarnings:
        print(warning)
    print(separationNumber * "*")
    print("Error/Warnings Review finished")
    print("For more information check the file:")
    print(separationNumber * "*")
    print("Number of project errors:", len(projErrors))
    print("Number of project warnings:", len(projWarnings))
    print("Number of libraries errors:", librariesErrorsNumber)
    print("Number of libraries warnings:", librariesWarningsNumber)

    sys.exit(len(projErrors) + len(projWarnings))
